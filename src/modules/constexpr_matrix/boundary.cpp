/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Compile-Time Fixed-Size Dense Matrix with LU Solver.
 * Module: constexpr_matrix
 */

#ifndef BOUNDARY_CONSTEXPR_MATRIX_H
#define BOUNDARY_CONSTEXPR_MATRIX_H

#include <math.h>
#include <stdbool.h>

static inline bool constexpr_matrix_is_finite_input(double x) {
    return isfinite(x);
}

static inline double constexpr_matrix_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_CONSTEXPR_MATRIX_H */
