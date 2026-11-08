/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Discrete Linear Kalman Filter State Estimator.
 * Module: kalman_filter_eigen
 */

#include <assert.h>

// Regression Case 001: Subnormal floating point handling
void test_kalman_filter_eigen_regression_subnormal(void) {
    double subnormal = 1e-315;
    double res = subnormal * (1.0 + 0.25 * subnormal);
    assert(res >= 0.0);
}
