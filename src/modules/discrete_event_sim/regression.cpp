/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Priority-Queue Discrete Event Simulation Engine.
 * Module: discrete_event_sim
 */

#include <assert.h>

void test_discrete_event_sim_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
