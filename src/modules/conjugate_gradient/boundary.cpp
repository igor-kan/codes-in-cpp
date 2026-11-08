/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Preconditioned Conjugate Gradient Sparse Linear Solver.
 * Module: conjugate_gradient
 */

#ifndef BOUNDARY_CONJUGATE_GRADIENT_H
#define BOUNDARY_CONJUGATE_GRADIENT_H

#include <math.h>
#include <stdbool.h>

static inline bool conjugate_gradient_is_finite_input(double x) {
    return isfinite(x);
}

static inline double conjugate_gradient_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_CONJUGATE_GRADIENT_H */
