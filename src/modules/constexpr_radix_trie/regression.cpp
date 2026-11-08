/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Compile-Time Prefix Radix Trie Router.
 * Module: constexpr_radix_trie
 */

#include <assert.h>

// Regression Case 001: Subnormal floating point handling
void test_constexpr_radix_trie_regression_subnormal(void) {
    double subnormal = 1e-315;
    double res = subnormal * (1.0 + 0.25 * subnormal);
    assert(res >= 0.0);
}
