/**
 * @file errors.cpp
 * @brief Domain diagnostic error codes and messages for Continuous Bisection Root-Finding Bracketing Engine.
 * Module: bisection_root_solver
 */

typedef enum bisection_root_solver_error {
    BISECTION_ROOT_SOLVER_SUCCESS = 0,
    BISECTION_ROOT_SOLVER_ERR_INVALID_INPUT = -1,
    BISECTION_ROOT_SOLVER_ERR_BUFFER_OVERFLOW = -2,
    BISECTION_ROOT_SOLVER_ERR_CONVERGENCE_FAIL = -3
} bisection_root_solver_error_t;

const char* bisection_root_solver_str_error(bisection_root_solver_error_t code) {
    switch (code) {
        case BISECTION_ROOT_SOLVER_SUCCESS: return "Operation completed successfully";
        case BISECTION_ROOT_SOLVER_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case BISECTION_ROOT_SOLVER_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case BISECTION_ROOT_SOLVER_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
