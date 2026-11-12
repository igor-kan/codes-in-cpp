/**
 * @file boundary.cpp
 * @brief Boundary validation, clamping, and edge-case guards for Horner Rule and Estrin Scheme Polynomial Evaluation.
 * Module: fast_polynomial_eval
 */

#include "types.cpp"
#include <math.h>
#include <stdbool.h>

static inline bool fast_polynomial_eval_is_finite(double v) {
    return isfinite(v);
}

static inline double fast_polynomial_eval_clamp_range(double v, double lo, double hi) {
    if (!isfinite(v)) return 0.0;
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}
