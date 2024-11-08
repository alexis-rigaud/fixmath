/*  Copyright (C) 2005-2011, Axis Communications AB, LUND, SWEDEN
 *  Copyright (C) 2024, Alexis Rigaud
 *
 *  SPDX-License-Identifier: LGPL-3.0-or-later
 *  SPDX-License-Identifier: GFDL-1.3-or-later
 */
/**
 *  @file   fixmath_ver.h
 *  @brief  Fixmath version numbers.
 */

#ifndef FX_VERSION_H
#define FX_VERSION_H

#include "fixmath_export.h"

#ifdef __cplusplus
extern "C" {
#endif


/*
 * -------------------------------------------------------------
 *  Constants
 * -------------------------------------------------------------
 */

#define STATIC_ASSERT(CONDITION) \
typedef char static_assert[(CONDITION)?1:-1]

/**
 *  The compile-time major version number.
 */
#ifndef FX_VERSION
#pragma message "FX_VERSION not set, set it to zero"
#define FX_VERSION 0
#endif /* FX_VERSION */

/**
 *  The compile-time minor version number.
 */
#ifndef FX_MINOR
#pragma message "FX_MINOR not set, set it to zero"
#define FX_MINOR 0
#endif /* FX_MINOR */

/*
 * -------------------------------------------------------------
 *  Global variables
 * -------------------------------------------------------------
 */

/**
 *  The run-time major version number.
 */
extern const FX_EXPORT unsigned int fx_version;

/**
 *  The run-time minor version number.
 */
extern const FX_EXPORT unsigned int fx_minor;

#ifdef __cplusplus
};
#endif

#endif /* FX_VERSION_H */

