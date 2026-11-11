/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for Minimal Residual (MINRES) Symmetric Indefinite Solver.
 * Module: minres_iterative_solver
 */

typedef enum minres_iterative_solver_error_code {
    MINRES_ITERATIVE_SOLVER_STATUS_OK = 0,
    MINRES_ITERATIVE_SOLVER_ERR_NULL_PTR = -20,
    MINRES_ITERATIVE_SOLVER_ERR_OUT_OF_BOUNDS = -21,
    MINRES_ITERATIVE_SOLVER_ERR_DIVERGENCE = -22
} minres_iterative_solver_error_code_t;

const char* minres_iterative_solver_error_message(minres_iterative_solver_error_code_t code) {
    switch (code) {
        case MINRES_ITERATIVE_SOLVER_STATUS_OK: return "Operational success";
        case MINRES_ITERATIVE_SOLVER_ERR_NULL_PTR: return "Null pointer argument";
        case MINRES_ITERATIVE_SOLVER_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case MINRES_ITERATIVE_SOLVER_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
