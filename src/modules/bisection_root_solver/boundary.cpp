/**
 * @file boundary.cpp
 * @brief Boundary validation, clamping, and edge-case guards for Continuous Bisection Root-Finding Bracketing Engine.
 * Module: bisection_root_solver
 */

#include "types.cpp"
#include <math.h>
#include <stdbool.h>

static inline bool bisection_root_solver_is_finite(double v) {
    return isfinite(v);
}

static inline double bisection_root_solver_clamp_range(double v, double lo, double hi) {
    if (!isfinite(v)) return 0.0;
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}
