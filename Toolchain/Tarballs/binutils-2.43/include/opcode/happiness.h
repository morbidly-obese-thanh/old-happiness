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

#ifndef _HAPPINESS_OPCODES_H
#define _HAPPINESS_OPCODES_H

#define HAPPINESS_NUM_REGISTERS 64

#ifndef HAPPINESS_BYTES_SLOT_INSTRUCTION
#define HAPPINESS_BYTES_SLOT_INSTRUCTION 4
#endif

#ifndef HAPPINESS_BYTES_SLOT_IMMEDIATE
#define HAPPINESS_BYTES_SLOT_IMMEDIATE 4
#endif

enum happiness_opcode {
  OP_NOP = 0,
  OP_JUMP = 1,
  OP_JUMP_REL = 2,
  OP_STORE = 17,
  OP_LOAD = 25,
  OP_MOV = 94,
  OP_ADD = 95
};

enum happiness_admode {
  AM_01000 = 8,  /* reg = imm */
  AM_01001 = 9,  /* reg = op(reg) */
  AM_01010 = 10, /* reg = op(reg, imm) */
  AM_01011 = 11, /* reg = op(reg, reg) */
};

typedef struct {
  int pad;    /* immediate present, 1-bit */
  int opcode; /* opcode, occupies 7-bit */
  int admode; /* address mode, 6-bit */
  int src0;   /* source 0 register, 6-bit */
  int src1;   /* source 1 register, 6-bit */
  int dst;    /* dest. register, 6-bit */
  int immv;   /* immediate, 32-bit only? */
} happiness_slot_insn;

#endif
