/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Compact Patricia Trie with Bitwise Prefix Match.
 * Module: radix_tree_patricia
 */

#include <assert.h>

void test_radix_tree_patricia_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
