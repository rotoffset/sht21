/*
 * Copyright (C) 2011 Sharp.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */
/* -------------------------------------------------------------------- */
#ifndef SH_KMOD_SHA256_HASH__
#define SH_KMOD_SHA256_HASH__

static const unsigned char kmod_sha256_hash[][32] = {
  {0xb6, 0x2b, 0x33, 0x36, 0x1b, 0xed, 0x0f, 0x73, 0xe9, 0x6e, 0x4b, 0xd1, 0xf4, 0xdd, 0x43, 0x0d, 0xac, 0xd1, 0x5e, 0x65, 0xdf, 0xc6, 0xc2, 0x67, 0xfa, 0xe5, 0xe3, 0xe3, 0x34, 0x25, 0x46, 0x3c}, /* shexfat.ko */
  {0x4f, 0x4e, 0xaf, 0x60, 0x81, 0x24, 0x4f, 0x2d, 0x5e, 0x42, 0x47, 0xac, 0x49, 0x62, 0x3a, 0x7a, 0x60, 0xfd, 0xb2, 0xa5, 0x12, 0x49, 0x9a, 0x0d, 0x40, 0x3f, 0x51, 0xe0, 0x4e, 0x99, 0x87, 0xa3}, /* cfg80211.ko */
  {0x08, 0x30, 0xee, 0x94, 0x20, 0xdf, 0x28, 0x19, 0xf9, 0xaf, 0x7c, 0x08, 0xc1, 0x6c, 0xf8, 0x62, 0x85, 0x17, 0x4f, 0x59, 0x1f, 0xaf, 0x3f, 0xea, 0x62, 0x3c, 0xf0, 0xfc, 0x86, 0x71, 0xbe, 0xa6}, /* prima_wlan.ko */
};

#endif /* SH_KMOD_SHA256_HASH__ */
