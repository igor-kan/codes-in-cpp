/**
 * @file errors.cpp
 * @brief Domain diagnostic error codes and messages for Barycentric Lagrange Polynomial Interpolator.
 * Module: polynomial_interpolation_lagrange
 */

typedef enum polynomial_interpolation_lagrange_error_status {
    POLYNOMIAL_INTERPOLATION_LAGRANGE_OK = 0,
    POLYNOMIAL_INTERPOLATION_LAGRANGE_ERR_INVALID_PARAM = -10,
    POLYNOMIAL_INTERPOLATION_LAGRANGE_ERR_CAPACITY_LIMIT = -11,
    POLYNOMIAL_INTERPOLATION_LAGRANGE_ERR_NUMERICAL_FAULT = -12
} polynomial_interpolation_lagrange_error_status_t;

const char* polynomial_interpolation_lagrange_error_string(polynomial_interpolation_lagrange_error_status_t err) {
    switch (err) {
        case POLYNOMIAL_INTERPOLATION_LAGRANGE_OK: return "Operational success";
        case POLYNOMIAL_INTERPOLATION_LAGRANGE_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case POLYNOMIAL_INTERPOLATION_LAGRANGE_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case POLYNOMIAL_INTERPOLATION_LAGRANGE_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
