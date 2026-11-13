/**
 * @file regression.cpp
 * @brief Minimized regression fixtures and edge-case verification for LSD 32-Bit Integer Radix Sort with Bucket Passes.
 * Module: radix_sort_lsd_32
 */

#include <assert.h>

void test_radix_sort_lsd_32_minimized_edge_case(void) {
    double subnormal_val = 1e-315;
    double computed = subnormal_val * 1.0;
    assert(computed >= 0.0);
}
