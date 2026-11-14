/**
 * @file errors.cpp
 * @brief Domain diagnostic error codes and messages for Chebyshev-Gauss Roots and Extrema Node Generator.
 * Module: chebyshev_nodes_gen
 */

typedef enum chebyshev_nodes_gen_error_status {
    CHEBYSHEV_NODES_GEN_OK = 0,
    CHEBYSHEV_NODES_GEN_ERR_INVALID_PARAM = -10,
    CHEBYSHEV_NODES_GEN_ERR_CAPACITY_LIMIT = -11,
    CHEBYSHEV_NODES_GEN_ERR_NUMERICAL_FAULT = -12
} chebyshev_nodes_gen_error_status_t;

const char* chebyshev_nodes_gen_error_string(chebyshev_nodes_gen_error_status_t err) {
    switch (err) {
        case CHEBYSHEV_NODES_GEN_OK: return "Operational success";
        case CHEBYSHEV_NODES_GEN_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case CHEBYSHEV_NODES_GEN_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case CHEBYSHEV_NODES_GEN_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
