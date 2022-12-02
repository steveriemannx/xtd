/// @file
/// @brief Contains internal math methods.
#pragma once
/// @cond
#ifndef __XTD_CORE_INTERNAL__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../types.h"

/// @cond
static constexpr xtd::decimal_t __get_epsilon(xtd::decimal_t) noexcept {return 0;}
static constexpr double __get_epsilon(double) noexcept {return 4.94066e-324;}
static constexpr float __get_epsilon(float) noexcept {return 1.401298E-45f;}
/// @endcond