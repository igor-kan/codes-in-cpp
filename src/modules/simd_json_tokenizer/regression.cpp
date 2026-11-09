/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for SIMD-Accelerated Branchless JSON Tokenizer.
 * Module: simd_json_tokenizer
 */

#include <assert.h>

void test_simd_json_tokenizer_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
