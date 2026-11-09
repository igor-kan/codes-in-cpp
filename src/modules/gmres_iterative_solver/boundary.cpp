/**
 * @file boundary.cpp
 * @brief Boundary validation and exceptional input guarding for Generalized Minimal Residual (GMRES) Sparse Solver.
 * Module: gmres_iterative_solver
 */

#include "types.cpp"
#include <math.h>
#include <stdbool.h>

static inline bool gmres_iterative_solver_is_valid_float(double x) {
    return isfinite(x);
}

static inline double gmres_iterative_solver_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
