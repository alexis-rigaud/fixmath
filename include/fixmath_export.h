/*  Copyright (C) 2005-2011, Axis Communications AB, LUND, SWEDEN
 *
 *  SPDX-License-Identifier: LGPL-3.0-or-later
 *  SPDX-License-Identifier: GFDL-1.3-or-later
 */
/*
 * -------------------------------------------------------------
 *  Constants
 * -------------------------------------------------------------
 */

/**
 *  Set the FX_EXPORT interface marker.
 */
#ifdef _MSC_VER
#ifdef FX_BUILD
#define FX_EXPORT __declspec(dllexport)
#else
#define FX_EXPORT __declspec(dllimport)
#endif

#elif __GNUC__ >= 4 || __GNUC__ == 3 && __GNUC_MINOR__ >= 3
#define FX_EXPORT __attribute__((__visibility__("default")))
#else

#define FX_EXPORT

#endif /* FIXMATH_EXPORT_H */
