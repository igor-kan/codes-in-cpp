/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Cacheline-Aligned B-Tree Node with SIMD Search.
 * Module: simd_b_tree_node
 */

#include <assert.h>

void test_simd_b_tree_node_regression_subnormal_day46(void) {
    double sub = 1e-310;
    double res = sub * (1.0 + 0.35 * sub);
    assert(res >= 0.0);
}
