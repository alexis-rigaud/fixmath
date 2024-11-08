/*  Copyright (C) 2005-2011, Axis Communications AB, LUND, SWEDEN
 *
 *  SPDX-License-Identifier: LGPL-3.0-or-later
 *  SPDX-License-Identifier: GFDL-1.3-or-later
 */

/**
 *  @file   fixmath_impl.h
 *  @brief  Fixed-point math library - core macro implementations.
 */

#ifndef FIXMATH_IMPL_H
#define FIXMATH_IMPL_H

#ifndef FIXMATH_H
#error "Do not include this file directly - use fixmath.h instead!"
#endif /* !FIXMATH_H */

#include <stdint.h> /* Fixed-size integers */
#include <stdlib.h> /* labs()              */

/*
 * -------------------------------------------------------------
 *  Lookup tables
 * -------------------------------------------------------------
 */

__attribute__((__visibility__("default"))) extern const float  fx_xtof_tab[32];
__attribute__((__visibility__("default"))) extern const double fx_xtod_tab[32];

/*
 * -------------------------------------------------------------
 *  Macros
 * -------------------------------------------------------------
 */

#define FX_IMPL_CLZ(ret, word) \
do {                           \
    uint32_t w__ = (word);     \
    w__ |= (w__ >>  1);        \
    w__ |= (w__ >>  2);        \
    w__ |= (w__ >>  4);        \
    w__ |= (w__ >>  8);        \
    w__ |= (w__ >> 16);        \
    (ret) = fx_bitcount(~w__); \
} while (0)

#define FX_IMPL_CTZ(ret, word) \
do {                           \
    uint32_t w__ = (word);     \
    w__ |= (w__ <<  1);        \
    w__ |= (w__ <<  2);        \
    w__ |= (w__ <<  4);        \
    w__ |= (w__ <<  8);        \
    w__ |= (w__ << 16);        \
    (ret) = fx_bitcount(~w__); \
} while (0)

#define FX_IMPL_BITCOUNT(ret, word)                           \
do {                                                          \
    uint32_t u__ = (word);                                    \
    u__ = u__ - ((u__ >> 1) & 0x55555555UL);                  \
    u__ = (u__ & 0x33333333UL) + ((u__ >> 2) & 0x33333333UL); \
    (ret) = (((u__ + (u__ >> 4)) & UINT32_C(0xf0f0f0f)) *     \
             UINT32_C(0x1010101)) >> 24;                      \
} while (0)

#define FX_IMPL_ITOX(ival, frac) \
    ((int32_t)(ival) << (frac))

#define FX_IMPL_FTOX(fval, frac)                       \
    (int32_t)((float)(fval) * (float)(1UL << (frac)) + \
             ((float)(fval) > 0 ? 0.5f : -0.5f))

#define FX_IMPL_DTOX(dval, frac)                         \
    (int32_t)((double)(dval) * (double)(1UL << (frac)) + \
             ((double)(dval) > 0 ? 0.5 : -0.5))

#define FX_IMPL_XTOX(xval, frac1, frac2)                           \
    ((frac2) >= (frac1) ? (int32_t)(xval) << ((frac2) - (frac1)) : \
                          FX_IMPL_ROUNDX(xval, (frac1) - (frac2)))

#define FX_IMPL_XTOI(xval, frac) \
    FX_IMPL_FLOORX(xval, frac)

#define FX_IMPL_XTOF(xval, frac) \
    ((float)(xval) * fx_xtof_tab[(frac) & 31])

#define FX_IMPL_XTOD(xval, frac) \
    ((double)(xval) * fx_xtod_tab[(frac) & 31])

#define FX_IMPL_ROUNDX(xval, frac) \
    (int32_t)((frac) ? (((xval) >> ((frac) - 1)) + 1) >> 1 : (xval))

#define FX_IMPL_CEILX(xval, frac) \
    (int32_t)(((int64_t)(xval) + (int64_t)((1UL << (frac)) - 1)) >> (frac))

#define FX_IMPL_FLOORX(xval, frac) \
    ((int32_t)(xval) >> (frac))

#define FX_IMPL_ADDX(x1, x2) \
    ((x1) + (x2))

#define FX_IMPL_SUBX(x1, x2) \
    ((x1) - (x2))

#define FX_IMPL_MULX(x1, x2, frac)                             \
    (int32_t)((frac) ?                                         \
    (((int64_t)(x1)*(int64_t)(x2) >> ((frac) - 1)) + 1) >> 1 : \
      (int32_t)(x1)*(int32_t)(x2))

#define FX_IMPL_DIVX(x1, x2, frac)                                    \
    (int32_t)((((int64_t)(x1) << (frac)) +                            \
               ((int32_t)(x1) < 0 ? -labs(x2) : labs(x2)) / 2) / (x2))

#define FX_IMPL_RDIVX(xval, rdiv) \
    FX_IMPL_MULX(xval, (rdiv)->mant, (rdiv)->expn)

#endif /* FIXMATH_IMPL_H */
