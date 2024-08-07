/* OnDemand Happiness-specific support for 32-bit ELF.
   Copyright (C) 2012-2024 Free Software Foundation, Inc.

   This file is part of BFD, the Binary File Descriptor library.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA
   02110-1301, USA.  */

#include "as.h"
#include "bfd.h"
#include "opcode/happiness.h"

const char *md_shortopts = "";

struct option md_longopts[] = {};

size_t md_longopts_size = sizeof(md_longopts);

/* Comment characters and separators. */
const char comment_chars[] = "";
const char line_comment_chars[] = "//";
const char line_separator_chars[] = ";";
const char EXP_CHARS[] = "";
const char FLT_CHARS[] = "";

/* No pseudo ops yet. */
const pseudo_typeS md_pseudo_table[] = {{(char *)0, (void (*)(int))0, 0}};

htab_t reg_table;

/* Can't parse if there are no opts. */
int md_parse_option(int c, const char *arg) { return 0; }

/* Command line usage. */
void md_show_usage(FILE *stream) {
  fprintf(stream, "\nHappiness options: none available yet\n");
}

/* See if the specified name is a register (r0-r63). Nothing actually to parse
 * here, just look up in the register table. */
static int happiness_parse_register(const char *name, expressionS *resultP) {
  symbolS *reg_sym = str_hash_find(reg_table, name);

  if (reg_sym != 0) {
    resultP->X_op = O_register;
    resultP->X_add_number = S_GET_VALUE(reg_sym);
    return 1;
  }

  return 0;
}

/* Happiness supports a bazillion of 'port' instructions, we keep things simple
 * and support only the 'port32' keyword. */
static int happiness_parse_port(const char *name, expressionS *resultP) {
  if (0 == strcmp(name, "port32")) {
    /* Need to clear this explicitly to avoid sporadic crashes for especially
     * crazy nested constructions. */
    resultP->X_op_symbol = 0;
    resultP->X_add_symbol = 0;
    resultP->X_op = O_port;
    return 1;
  }

  return 0;
}

/* Catch 'jump' and 'jrel' here now. */
static int happiness_parse_branch(const char *name, expressionS *resultP,
                                  char *next_char) {
  /* This is slightly more involved since we are going to extract the target
   * operand inline. */
  expressionS op_expr;

  int seen_parenthesis = 0;
  int is_jump = !strcmp(name, "jump");
  int is_jrel = !strcmp(name, "jrel");

  if (!(is_jump || is_jrel)) {
    return 0;
  }

  /* Point 'input_line_pointer' to start at 'next_char' and remove any
   * whitespace from the head. */
  (void)restore_line_pointer(*next_char);
  SKIP_WHITESPACE();

  if ('(' == *input_line_pointer) {
    seen_parenthesis = 1;
    input_line_pointer++;
  } else {
    /* Allow but warn about operands without parenthesis. */
    as_warn("missing '(' in 'jump/jrel' instruction syntax");
  }

  /* Now parse the target operand. */
  memset(&op_expr, 0, sizeof(expressionS));
  expression(&op_expr);

  resultP->X_add_symbol = make_expr_symbol(&op_expr);
  resultP->X_op = is_jump ? O_jump : O_jrel;

  if (1 == seen_parenthesis) {
    if (')' != *input_line_pointer) {
      as_bad("missing ')' in 'jump/jrel' instruction syntax");
    } else {
      ++input_line_pointer;
    }
  }

  if (*input_line_pointer != '\0') {
    as_bad("unexpected '%c' in 'jump/jrel' instruction syntax",
           *input_line_pointer);
  }

  /* Need to mark 'next_char' properly otherwise 'input_line_pointer' will be
   * reset to the position right after 'jump/jrel.' */
  *next_char = *input_line_pointer;
  return 1;
}

/* If any of the checks above fail, assume to be dealing with a symbol. */
static int happiness_parse_symbol(const char *name, expressionS *resultP) {
  symbolS *sym = symbol_find_or_make(name);
  know(sym != 0);

  resultP->X_op = O_symbol;
  resultP->X_add_symbol = sym;

  /* This is kind of a hack. A dummy value to avoid 'make_expr_symbol' turn the
   * node into 'O_constant.' */
  resultP->X_add_number = 1;
  return 1;
}

/* In order to catch assembler keywords and assign them properly, hook in a
 * custom name checking routine. */
int happiness_parse_name(const char *name, expressionS *resultP,
                         char *next_char) {
  gas_assert(name != 0 && resultP != 0);

  if (happiness_parse_register(name, resultP) != 0) {
    return 1;
  }

  if (happiness_parse_port(name, resultP) != 0) {
    return 1;
  }

  if (happiness_parse_branch(name, resultP, next_char) != 0) {
    return 1;
  }

  if (happiness_parse_symbol(name, resultP) != 0) {
    return 1;
  }

  return 0;
}

/* Do any architecture specific initialization, we use this to set up the table
 * of registers that we treat as already known 'symbols.' */
void md_begin(void) {
  int i;
  reg_table = str_htab_create();

  for (i = 0; i < HAPPINESS_NUM_REGISTERS; ++i) {
    char name[4];

    sprintf(name, "r%d", i);

    symbolS *reg_sym = symbol_new(name, reg_section, &zero_address_frag, i);

    /* We insert registers as 'symbolS' with no correspondence to a
     * 'bfd_symbol.' */
    if (str_hash_insert(reg_table, S_GET_NAME(reg_sym), reg_sym, 0)) {
      as_fatal(_("failed creating register symbols"));
    }
  }
}

/* Distinguish instruction types and initiate building. */
static bfd_boolean happiness_build_insn(happiness_slot_insn *insn,
                                        expressionS *lhs, expressionS *rhs) {
  gas_assert(lhs != 0);

  switch (lhs->X_op) {
  case O_register: {
    /* Instruction writes to a register, the type depends on rhs. */
    gas_assert(rhs != 0);

    if (O_register == rhs->X_op || O_constant == rhs->X_op) {
      printf("Building a 'move' instruction\n");
      return true;
    } else if (O_add == rhs->X_op) {
      printf("Building an 'add' instruction\n");
      return true;
    } else if (O_index == rhs->X_op) {
      printf("Building a 'load' instruction\n");
      return true;
    }

    break;
  }

  case O_index: {
    printf("Building a 'store' instruction\n");
    return true;
  }

  case O_jump:
  case O_jrel: {
    printf("Building a 'jump/jrel' instruction\n");
    return true;
  }

  default:
    break;
  }

  return false;
}

/* Main assembler hook, called once for each "instruction string." */
void md_assemble(char *insn_str) {
  printf("Assembling instruction string: %s\n", insn_str);

  happiness_slot_insn *insn = 0;
  expressionS lhs_info;
  expressionS rhs_info;

  int insn_done = 0;
  int assign_pos;
  char *assign;

  /* reg = reg/imm32  <register/immediate move>
   * reg = port[reg]  <memory reads>
   * port[reg] = reg  <memory writes>
   * jump(reg/symbol) <absolute branches>
   * jrel(reg/symbol) <relative branches>
   * reg = reg + reg  <binary arithmetic> */

  /* The very first step is to decompose the instruction string into 'lhs' and
   * 'rhs', thus, look for '=' in the string. */
  assign = strchr(insn_str, '=');

  /* Set temporarily to contain the instruction string only. */
  input_line_pointer = insn_str;

  memset(&lhs_info, 0, sizeof(expressionS));
  expression(&lhs_info);

  insn = (happiness_slot_insn *)malloc(sizeof(happiness_slot_insn));

  if (assign) {
    assign_pos = assign - insn_str;

    /* Advance past the '=' character and parse the expression located on the
     * rhs. */
    input_line_pointer = ++assign;

    memset(&rhs_info, 0, sizeof(expressionS));
    expression(&rhs_info);

    /* Now call the top-level instruction builder. */
    insn_done = happiness_build_insn(insn, &lhs_info, &rhs_info);
  } else {
    /* Now call the top-level instruction builder. */
    insn_done = happiness_build_insn(insn, &lhs_info, 0);
  }

  if (!insn_done) {
    as_fatal(_("Could not build instruction"));
  }

  return;
}

/* Be notified about undefined symbols. */
symbolS *md_undefined_symbol(char *name) {
  as_bad("undefined symbol '%s'\n", name);
  return 0;
}

/* Again, no floating point expressions available. */
const char *md_atof(int type, char *lit, int *size) { return 0; }

/* Can't round up sections yet. */
valueT md_section_align(asection *seg, valueT val) { return 0; }

/* Also, generally no support for frag conversion. */
void md_convert_frag(bfd *abfd, asection *seg, fragS *fragp) {
  as_fatal(_("unexpected call"));
  return;
}

/* Not possible, instead convert to relocs and write them. */
void md_apply_fix(fixS *fixp, valueT *val, segT seg) { return; }

/* If not applied/resolved, turn a fixup into a relocation entry. */
arelent *tc_gen_reloc(asection *seg, fixS *fixp) { return 0; }

/* No pc-relative relocations yet, might provide one later for experiments. */
long md_pcrel_from(fixS *fixp) {
  as_fatal(_("unexpected call"));
  return 0;
}

/* All instructions and immediates are fixed in size, therefore no relaxation
 * required. */
int md_estimate_size_before_relax(fragS *fragp, asection *seg) {
  as_fatal(_("unexpected call"));
  return 0;
}
