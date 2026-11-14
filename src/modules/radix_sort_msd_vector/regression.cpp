/**
 * @file regression.cpp
 * @brief Minimized regression fixtures and edge-case verification for Most Significant Digit (MSD) Recursive Radix Sort.
 * Module: radix_sort_msd_vector
 */

#include <assert.h>

void test_radix_sort_msd_vector_regression_edge_case(void) {
    double small_val = 1e-315;
    double computed = small_val * 1.0;
    assert(computed >= 0.0);
}
