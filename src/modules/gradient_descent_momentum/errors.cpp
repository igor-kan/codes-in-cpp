/**
 * @file errors.cpp
 * @brief Domain diagnostic error codes and messages for Gradient Descent Optimizer with Nesterov Momentum.
 * Module: gradient_descent_momentum
 */

typedef enum gradient_descent_momentum_error_status {
    GRADIENT_DESCENT_MOMENTUM_OK = 0,
    GRADIENT_DESCENT_MOMENTUM_ERR_INVALID_PARAM = -10,
    GRADIENT_DESCENT_MOMENTUM_ERR_CAPACITY_LIMIT = -11,
    GRADIENT_DESCENT_MOMENTUM_ERR_NUMERICAL_FAULT = -12
} gradient_descent_momentum_error_status_t;

const char* gradient_descent_momentum_error_string(gradient_descent_momentum_error_status_t err) {
    switch (err) {
        case GRADIENT_DESCENT_MOMENTUM_OK: return "Operational success";
        case GRADIENT_DESCENT_MOMENTUM_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case GRADIENT_DESCENT_MOMENTUM_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case GRADIENT_DESCENT_MOMENTUM_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
