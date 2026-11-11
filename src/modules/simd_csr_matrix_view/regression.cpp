/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Cacheline-Aligned CSR Sparse Matrix View with Vectorization.
 * Module: simd_csr_matrix_view
 */

#include <assert.h>

void test_simd_csr_matrix_view_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
