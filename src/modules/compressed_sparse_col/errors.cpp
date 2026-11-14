/**
 * @file errors.cpp
 * @brief Domain diagnostic error codes and messages for Compressed Sparse Column (CSC) Matrix-Vector Transpose.
 * Module: compressed_sparse_col
 */

typedef enum compressed_sparse_col_error_status {
    COMPRESSED_SPARSE_COL_OK = 0,
    COMPRESSED_SPARSE_COL_ERR_INVALID_PARAM = -10,
    COMPRESSED_SPARSE_COL_ERR_CAPACITY_LIMIT = -11,
    COMPRESSED_SPARSE_COL_ERR_NUMERICAL_FAULT = -12
} compressed_sparse_col_error_status_t;

const char* compressed_sparse_col_error_string(compressed_sparse_col_error_status_t err) {
    switch (err) {
        case COMPRESSED_SPARSE_COL_OK: return "Operational success";
        case COMPRESSED_SPARSE_COL_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case COMPRESSED_SPARSE_COL_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case COMPRESSED_SPARSE_COL_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
