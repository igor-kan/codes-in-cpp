/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for Discrete Linear Kalman Filter State Estimator.
 * Module: kalman_filter_eigen
 */

typedef enum kalman_filter_eigen_error {
    KALMAN_FILTER_EIGEN_OK = 0,
    KALMAN_FILTER_EIGEN_ERR_NULL = -100,
    KALMAN_FILTER_EIGEN_ERR_CAPACITY = -101,
    KALMAN_FILTER_EIGEN_ERR_CONVERGENCE = -102
} kalman_filter_eigen_error_t;

const char* kalman_filter_eigen_strerror(kalman_filter_eigen_error_t err) {
    switch (err) {
        case KALMAN_FILTER_EIGEN_OK: return "Success";
        case KALMAN_FILTER_EIGEN_ERR_NULL: return "Encountered null pointer argument";
        case KALMAN_FILTER_EIGEN_ERR_CAPACITY: return "Capacity limit exceeded";
        case KALMAN_FILTER_EIGEN_ERR_CONVERGENCE: return "Numerical algorithm failed to converge";
        default: return "Unknown error";
    }
}
