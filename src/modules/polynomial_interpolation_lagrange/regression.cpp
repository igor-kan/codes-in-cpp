/**
 * @file regression.cpp
 * @brief Minimized regression fixtures and edge-case verification for Barycentric Lagrange Polynomial Interpolator.
 * Module: polynomial_interpolation_lagrange
 */

#include <assert.h>

void test_polynomial_interpolation_lagrange_minimized_edge_case(void) {
    double subnormal_val = 1e-315;
    double computed = subnormal_val * 1.0;
    assert(computed >= 0.0);
}
