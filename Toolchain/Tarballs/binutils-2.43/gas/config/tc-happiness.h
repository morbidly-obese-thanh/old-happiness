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

#ifndef TC_HAPPINESS_H
#define TC_HAPPINESS_H

#define TARGET_FORMAT "elf32-happiness"
#define TARGET_ARCH bfd_arch_happiness
#define TARGET_MACH bfd_mach_happiness
#define TARGET_BYTES_BIG_ENDIAN 0

#define md_operand(X)

#define md_number_to_chars number_to_chars_littleendian

#define WORKING_DOT_WORD

/* Define this to support indexing using subscripts, e.g. 'port32[r1].' */
#define NEED_INDEX_OPERATOR 1

/* Most of the targets instructions use '=', thus allow explicitly. */
#define TC_EQUAL_IN_INSN(C, NAME) 1

/* Avoid register expressions such as 'r10+r11' being folded into 'r21.' */
#define md_register_arithmetic 0

/* Declare that we want our own name parsing. */
#define md_parse_name(str, expr, m, c) happiness_parse_name(str, expr, c)
int happiness_parse_name(const char *, expressionS *, char *);

/* Explicit machine expressions, remap to ones reserved for that purpose. */
#define O_port O_md1
#define O_jump O_md2
#define O_jrel O_md3

#endif
