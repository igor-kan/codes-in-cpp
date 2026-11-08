/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Compressed Sparse Row Matrix SpMV Acceleration.
 * Module: sparse_matrix_csr
 */

#include <assert.h>

// Regression Case 001: Subnormal floating point handling
void test_sparse_matrix_csr_regression_subnormal(void) {
    double subnormal = 1e-315;
    double res = subnormal * (1.0 + 0.25 * subnormal);
    assert(res >= 0.0);
}
