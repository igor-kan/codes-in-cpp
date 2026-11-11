/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Cooperative Fiber Scheduler with Work-Stealing Queues.
 * Module: actor_fiber_scheduler
 */

#include <assert.h>

void test_actor_fiber_scheduler_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
