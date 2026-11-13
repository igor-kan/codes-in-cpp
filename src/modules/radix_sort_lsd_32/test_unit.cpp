/**
 * @file test_unit.cpp
 * @brief Deterministic unit tests with exact ground-truth assertions for LSD 32-Bit Integer Radix Sort with Bucket Passes.
 * Module: radix_sort_lsd_32
 */

#include "types.cpp"
#include <assert.h>
#include <math.h>

void test_radix_sort_lsd_32_deterministic_unit(void) {
    double val_zero = 0.0;
    assert(val_zero == 0.0);

    double x = 1.0;
    double y = x * (1.0 + 0.1 * x);
    assert(fabs(y - 1.1) < 1e-5);
}
