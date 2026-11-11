/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for Consteval Compile-Time Matrix Exponential via Pade.
 * Module: compile_time_matrix_exp
 */

typedef enum compile_time_matrix_exp_error_code {
    COMPILE_TIME_MATRIX_EXP_STATUS_OK = 0,
    COMPILE_TIME_MATRIX_EXP_ERR_NULL_PTR = -20,
    COMPILE_TIME_MATRIX_EXP_ERR_OUT_OF_BOUNDS = -21,
    COMPILE_TIME_MATRIX_EXP_ERR_DIVERGENCE = -22
} compile_time_matrix_exp_error_code_t;

const char* compile_time_matrix_exp_error_message(compile_time_matrix_exp_error_code_t code) {
    switch (code) {
        case COMPILE_TIME_MATRIX_EXP_STATUS_OK: return "Operational success";
        case COMPILE_TIME_MATRIX_EXP_ERR_NULL_PTR: return "Null pointer argument";
        case COMPILE_TIME_MATRIX_EXP_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case COMPILE_TIME_MATRIX_EXP_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
