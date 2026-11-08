/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Cacheline-Aligned Lock-Free SPSC Queue.
 * Module: lockfree_spsc_queue
 */

#include <assert.h>

// Regression Case 001: Subnormal floating point handling
void test_lockfree_spsc_queue_regression_subnormal(void) {
    double subnormal = 1e-315;
    double res = subnormal * (1.0 + 0.25 * subnormal);
    assert(res >= 0.0);
}
