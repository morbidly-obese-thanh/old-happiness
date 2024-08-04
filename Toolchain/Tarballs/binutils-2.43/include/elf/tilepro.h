/* TILEPro ELF support for BFD.
   Copyright (C) 2011-2024 Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#ifndef _ELF_TILEPRO_H
#define _ELF_TILEPRO_H

#include "elf/reloc-macros.h"

/* Relocations.  */
START_RELOC_NUMBERS (elf_tilepro_reloc_type)
  RELOC_NUMBER (R_TILEPRO_NONE,        0)

  /* Standard relocations */
  RELOC_NUMBER (R_TILEPRO_32,                  1)
  RELOC_NUMBER (R_TILEPRO_16,                  2)
  RELOC_NUMBER (R_TILEPRO_8,                   3)
  RELOC_NUMBER (R_TILEPRO_32_PCREL,            4)
  RELOC_NUMBER (R_TILEPRO_16_PCREL,            5)
  RELOC_NUMBER (R_TILEPRO_8_PCREL,             6)

  RELOC_NUMBER (R_TILEPRO_LO16,                7)
  RELOC_NUMBER (R_TILEPRO_HI16,                8)
  RELOC_NUMBER (R_TILEPRO_HA16,                9)

  RELOC_NUMBER (R_TILEPRO_COPY,               10)
  RELOC_NUMBER (R_TILEPRO_GLOB_DAT,           11)
  RELOC_NUMBER (R_TILEPRO_JMP_SLOT,           12)
  RELOC_NUMBER (R_TILEPRO_RELATIVE,           13)

  /* Branch/jump offsets */
  RELOC_NUMBER (R_TILEPRO_BROFF_X1,           14)
  RELOC_NUMBER (R_TILEPRO_JOFFLONG_X1,        15)
  RELOC_NUMBER (R_TILEPRO_JOFFLONG_X1_PLT,    16)

  /* Immediate operands. */
  RELOC_NUMBER (R_TILEPRO_IMM8_X0,            17)
  RELOC_NUMBER (R_TILEPRO_IMM8_Y0,            18)
  RELOC_NUMBER (R_TILEPRO_IMM8_X1,            19)
  RELOC_NUMBER (R_TILEPRO_IMM8_Y1,            20)
  RELOC_NUMBER (R_TILEPRO_MT_IMM15_X1,        21)
  RELOC_NUMBER (R_TILEPRO_MF_IMM15_X1,        22)

  RELOC_NUMBER (R_TILEPRO_IMM16_X0,           23)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1,           24)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_LO,        25)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_LO,        26)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_HI,        27)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_HI,        28)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_HA,        29)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_HA,        30)

  RELOC_NUMBER (R_TILEPRO_IMM16_X0_PCREL,     31)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_PCREL,     32)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_LO_PCREL,  33)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_LO_PCREL,  34)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_HI_PCREL,  35)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_HI_PCREL,  36)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_HA_PCREL,  37)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_HA_PCREL,  38)

  RELOC_NUMBER (R_TILEPRO_IMM16_X0_GOT,       39)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_GOT,       40)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_GOT_LO,    41)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_GOT_LO,    42)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_GOT_HI,    43)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_GOT_HI,    44)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_GOT_HA,    45)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_GOT_HA,    46)

  RELOC_NUMBER (R_TILEPRO_MMSTART_X0,         47)
  RELOC_NUMBER (R_TILEPRO_MMEND_X0,           48)
  RELOC_NUMBER (R_TILEPRO_MMSTART_X1,         49)
  RELOC_NUMBER (R_TILEPRO_MMEND_X1,           50)

  RELOC_NUMBER (R_TILEPRO_SHAMT_X0,           51)
  RELOC_NUMBER (R_TILEPRO_SHAMT_X1,           52)
  RELOC_NUMBER (R_TILEPRO_SHAMT_Y0,           53)
  RELOC_NUMBER (R_TILEPRO_SHAMT_Y1,           54)

  RELOC_NUMBER (R_TILEPRO_DEST_IMM8_X1,       55)

  /* Relocs 56-59 are currently not defined.  */

  RELOC_NUMBER (R_TILEPRO_TLS_GD_CALL,        60)
  RELOC_NUMBER (R_TILEPRO_IMM8_X0_TLS_GD_ADD, 61)
  RELOC_NUMBER (R_TILEPRO_IMM8_X1_TLS_GD_ADD, 62)
  RELOC_NUMBER (R_TILEPRO_IMM8_Y0_TLS_GD_ADD, 63)
  RELOC_NUMBER (R_TILEPRO_IMM8_Y1_TLS_GD_ADD, 64)
  RELOC_NUMBER (R_TILEPRO_TLS_IE_LOAD,        65)

  RELOC_NUMBER (R_TILEPRO_IMM16_X0_TLS_GD,    66)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_TLS_GD,    67)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_TLS_GD_LO, 68)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_TLS_GD_LO, 69)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_TLS_GD_HI, 70)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_TLS_GD_HI, 71)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_TLS_GD_HA, 72)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_TLS_GD_HA, 73)

  RELOC_NUMBER (R_TILEPRO_IMM16_X0_TLS_IE,    74)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_TLS_IE,    75)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_TLS_IE_LO, 76)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_TLS_IE_LO, 77)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_TLS_IE_HI, 78)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_TLS_IE_HI, 79)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_TLS_IE_HA, 80)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_TLS_IE_HA, 81)

  RELOC_NUMBER (R_TILEPRO_TLS_DTPMOD32,       82)
  RELOC_NUMBER (R_TILEPRO_TLS_DTPOFF32,       83)
  RELOC_NUMBER (R_TILEPRO_TLS_TPOFF32,        84)

  RELOC_NUMBER (R_TILEPRO_IMM16_X0_TLS_LE,    85)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_TLS_LE,    86)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_TLS_LE_LO, 87)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_TLS_LE_LO, 88)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_TLS_LE_HI, 89)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_TLS_LE_HI, 90)
  RELOC_NUMBER (R_TILEPRO_IMM16_X0_TLS_LE_HA, 91)
  RELOC_NUMBER (R_TILEPRO_IMM16_X1_TLS_LE_HA, 92)

/* These are GNU extensions to enable C++ vtable garbage collection.  */
  RELOC_NUMBER (R_TILEPRO_GNU_VTINHERIT, 128)
  RELOC_NUMBER (R_TILEPRO_GNU_VTENTRY, 129)
END_RELOC_NUMBERS (R_TILEPRO_max)

#endif /* _ELF_TILEPRO_H */
