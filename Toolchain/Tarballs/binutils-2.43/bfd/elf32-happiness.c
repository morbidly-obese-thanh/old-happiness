/* OnDemand Happiness specific support for 32-bit ELF
   Copyright (C) 1994-2024 Free Software Foundation, Inc.

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

// clang-format off
#include "sysdep.h"
#include "bfd.h"
#include "libbfd.h"
#include "elf-bfd.h"
// clang-format on

static reloc_howto_type *
happiness_reloc_type_lookup(bfd *abfd, bfd_reloc_code_real_type code) {
  return 0;
}

static reloc_howto_type *happiness_reloc_name_lookup(bfd *abfd,
                                                     const char *name) {
  return 0;
}

#define bfd_elf32_bfd_reloc_type_lookup happiness_reloc_type_lookup
#define bfd_elf32_bfd_reloc_name_lookup happiness_reloc_name_lookup

#define ELF_ARCH bfd_arch_happiness
#define ELF_MAXPAGESIZE 0x4000
#define ELF_MACHINE_CODE EM_HAPPINESS

#undef TARGET_LITTLE_SYM
#define TARGET_LITTLE_SYM happiness_elf32_vec

#undef TARGET_LITTLE_NAME
#define TARGET_LITTLE_NAME "elf32-happiness"

#include "elf32-target.h"
