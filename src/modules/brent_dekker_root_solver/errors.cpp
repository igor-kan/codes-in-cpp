/**
 * @file errors.cpp
 * @brief Domain diagnostic error codes and messages for Brent-Dekker Hybrid Root Finder Combining Bisection.
 * Module: brent_dekker_root_solver
 */

typedef enum brent_dekker_root_solver_error_status {
    BRENT_DEKKER_ROOT_SOLVER_OK = 0,
    BRENT_DEKKER_ROOT_SOLVER_ERR_INVALID_PARAM = -10,
    BRENT_DEKKER_ROOT_SOLVER_ERR_CAPACITY_LIMIT = -11,
    BRENT_DEKKER_ROOT_SOLVER_ERR_NUMERICAL_FAULT = -12
} brent_dekker_root_solver_error_status_t;

const char* brent_dekker_root_solver_error_string(brent_dekker_root_solver_error_status_t err) {
    switch (err) {
        case BRENT_DEKKER_ROOT_SOLVER_OK: return "Operational success";
        case BRENT_DEKKER_ROOT_SOLVER_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case BRENT_DEKKER_ROOT_SOLVER_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case BRENT_DEKKER_ROOT_SOLVER_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
