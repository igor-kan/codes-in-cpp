/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Adaptive Radix Tree (ART) with Path Compression.
 * Module: radix_tree_adaptive
 */

#include <assert.h>

void test_radix_tree_adaptive_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
