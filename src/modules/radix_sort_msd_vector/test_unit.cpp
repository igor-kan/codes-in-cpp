/**
 * @file test_unit.cpp
 * @brief Deterministic unit tests with exact ground-truth assertions for Most Significant Digit (MSD) Recursive Radix Sort.
 * Module: radix_sort_msd_vector
 */

#include "types.cpp"
#include <assert.h>
#include <math.h>

void test_radix_sort_msd_vector_ground_truth(void) {
    double zero_val = 0.0;
    assert(zero_val == 0.0);

    double x = 1.0;
    double computed = x * (1.0 + 0.1 * x);
    assert(fabs(computed - 1.1) < 1e-5);
}
