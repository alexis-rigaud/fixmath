/*  Copyright (C) 2005-2011, Axis Communications AB, LUND, SWEDEN
 *  Copyright (C) 2024, Alexis Rigaud
 *
 *  SPDX-License-Identifier: LGPL-3.0-or-later
 *  SPDX-License-Identifier: GFDL-1.3-or-later
 */
/**
 *  @file   fixmath_arch.h
 *  @brief  Fixed-point math library - platform-specific definitions.
 */

#ifndef FIXMATH_ARCH_H
#define FIXMATH_ARCH_H

#ifndef FIXMATH_H
#error "Do not include this file directly - use fixmath.h instead!"
#endif /* !FIXMATH_H */

/*
 *  Set GCC-specific built-in functions.
 */
#ifdef __GNUC__
#if __GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#define fx_clz       __builtin_clz
#define fx_ctz       __builtin_ctz
#define fx_bitcount  __builtin_popcount
#endif /* __GNUC__ > 3 ... */
#endif /* __GNUC__ */

#endif /* FIXMATH_ARCH_H */
