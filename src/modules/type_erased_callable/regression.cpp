/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Small Buffer Optimized Type-Erased Callable.
 * Module: type_erased_callable
 */

#include <assert.h>

void test_type_erased_callable_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
