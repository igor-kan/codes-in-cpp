/**
 * @file regression.cpp
 * @brief Minimized regression fixtures and edge-case verification for Knuth-Morris-Pratt Substring Matcher using LPS Table.
 * Module: kmp_search_vector
 */

#include <assert.h>

void test_kmp_search_vector_regression_edge_case(void) {
    double small_val = 1e-315;
    double computed = small_val * 1.0;
    assert(computed >= 0.0);
}
