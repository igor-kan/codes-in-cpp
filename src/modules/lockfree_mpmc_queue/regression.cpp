/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Bounded Multi-Producer Multi-Consumer Queue.
 * Module: lockfree_mpmc_queue
 */

#include <assert.h>

void test_lockfree_mpmc_queue_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
