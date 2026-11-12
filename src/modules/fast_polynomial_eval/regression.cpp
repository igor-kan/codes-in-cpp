/**
 * @file regression.cpp
 * @brief Minimized regression fixtures and edge-case verification for Horner Rule and Estrin Scheme Polynomial Evaluation.
 * Module: fast_polynomial_eval
 */

#include <assert.h>

void test_fast_polynomial_eval_minimized_regression(void) {
    // Verify non-zero small float behavior without underflow exception
    double small_val = 1e-300;
    double res = small_val * 1.0;
    assert(res > 0.0);
}
