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

/* Can't parse if there are no opts. */
int md_parse_option(int c, const char *arg) { return 0; }

/* Command line usage. */
void md_show_usage(FILE *stream) {
  fprintf(stream, "\nHappiness options: none available yet\n");
}

/* Custom initializer hook, called once per assembler invocation. */
void md_begin(void) { return; }

/* Main assembler hook, called once for each "instruction string." */
void md_assemble(char *insn_str) { return; }

/* This gets invoked in case 'md_parse_name' has failed. */
symbolS *md_undefined_symbol(char *name) { return 0; }

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
