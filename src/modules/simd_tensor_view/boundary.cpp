/**
 * Boundary condition checking and IEEE-754 edge-case handlers for Strided Multi-Dimensional Tensor View with SIMD Alignment.
 * Module: simd_tensor_view
 */

#ifndef BOUNDARY_SIMD_TENSOR_VIEW_H
#define BOUNDARY_SIMD_TENSOR_VIEW_H

#include <math.h>
#include <stdbool.h>

static inline bool simd_tensor_view_is_finite_input(double x) {
    return isfinite(x);
}

static inline double simd_tensor_view_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_SIMD_TENSOR_VIEW_H */
