/**
 * @file errors.cpp
 * @brief Domain diagnostic error codes and messages for Horner Rule and Estrin Scheme Polynomial Evaluation.
 * Module: fast_polynomial_eval
 */

typedef enum fast_polynomial_eval_error {
    FAST_POLYNOMIAL_EVAL_SUCCESS = 0,
    FAST_POLYNOMIAL_EVAL_ERR_INVALID_INPUT = -1,
    FAST_POLYNOMIAL_EVAL_ERR_BUFFER_OVERFLOW = -2,
    FAST_POLYNOMIAL_EVAL_ERR_CONVERGENCE_FAIL = -3
} fast_polynomial_eval_error_t;

const char* fast_polynomial_eval_str_error(fast_polynomial_eval_error_t code) {
    switch (code) {
        case FAST_POLYNOMIAL_EVAL_SUCCESS: return "Operation completed successfully";
        case FAST_POLYNOMIAL_EVAL_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case FAST_POLYNOMIAL_EVAL_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case FAST_POLYNOMIAL_EVAL_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
