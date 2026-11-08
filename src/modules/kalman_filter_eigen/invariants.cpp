/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for Discrete Linear Kalman Filter State Estimator.
 * Module: kalman_filter_eigen
 */

#include <assert.h>
#include <math.h>

static inline void kalman_filter_eigen_assert_contract(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
