/**
 * @file core.cpp
 * @brief Primary computational implementation for Continuous Bisection Root-Finding Bracketing Engine.
 * Module: bisection_root_solver
 */

#include "types.cpp"
#include <stdlib.h>
#include <string.h>

int bisection_root_solver_compute_sequence(const double* in_vec, double* out_vec, size_t n, double param) {
    if (!in_vec || !out_vec || n == 0) return -1;
    for (size_t i = 0; i < n; ++i) {
        double x = in_vec[i];
        out_vec[i] = x * (1.0 + param * x / (1.0 + x * x));
    }
    return 0;
}
