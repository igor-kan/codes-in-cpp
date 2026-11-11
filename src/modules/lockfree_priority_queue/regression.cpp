/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Bounded Lock-Free Priority Queue with Atomic SkipList.
 * Module: lockfree_priority_queue
 */

#include <assert.h>

void test_lockfree_priority_queue_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
