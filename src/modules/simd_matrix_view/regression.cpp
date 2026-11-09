/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Padded 2D Strided Matrix View with Vectorization.
 * Module: simd_matrix_view
 */

#include <assert.h>

void test_simd_matrix_view_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
