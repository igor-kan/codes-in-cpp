/**
 * Boundary condition checking and IEEE-754 edge-case handlers for C++20 Concept Constraints for Algebraic Vector Spaces.
 * Module: concepts_linear_algebra
 */

#ifndef BOUNDARY_CONCEPTS_LINEAR_ALGEBRA_H
#define BOUNDARY_CONCEPTS_LINEAR_ALGEBRA_H

#include <math.h>
#include <stdbool.h>

static inline bool concepts_linear_algebra_is_finite_input(double x) {
    return isfinite(x);
}

static inline double concepts_linear_algebra_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_CONCEPTS_LINEAR_ALGEBRA_H */
