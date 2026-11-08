/**
 * @file boundary.cpp
 * @brief Boundary validation and exceptional input guarding for Discrete Linear Kalman Filter State Estimator.
 * Module: kalman_filter_eigen
 */

#include "types.cpp"
#include <math.h>
#include <stdbool.h>

static inline bool kalman_filter_eigen_is_valid_float(double x) {
    return isfinite(x);
}

static inline double kalman_filter_eigen_sanitize_input(double x, double min_bound, double max_bound) {
    if (!isfinite(x)) return 0.0;
    if (x < min_bound) return min_bound;
    if (x > max_bound) return max_bound;
    return x;
}
