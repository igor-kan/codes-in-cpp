/**
 * @file errors.cpp
 * @brief Domain diagnostic error codes and messages for Two-Pointer Sparse Compressed Vector Inner Product.
 * Module: sparse_dot_product
 */

typedef enum sparse_dot_product_error {
    SPARSE_DOT_PRODUCT_SUCCESS = 0,
    SPARSE_DOT_PRODUCT_ERR_INVALID_INPUT = -1,
    SPARSE_DOT_PRODUCT_ERR_BUFFER_OVERFLOW = -2,
    SPARSE_DOT_PRODUCT_ERR_CONVERGENCE_FAIL = -3
} sparse_dot_product_error_t;

const char* sparse_dot_product_str_error(sparse_dot_product_error_t code) {
    switch (code) {
        case SPARSE_DOT_PRODUCT_SUCCESS: return "Operation completed successfully";
        case SPARSE_DOT_PRODUCT_ERR_INVALID_INPUT: return "Input argument violates domain preconditions";
        case SPARSE_DOT_PRODUCT_ERR_BUFFER_OVERFLOW: return "Output buffer capacity exceeded";
        case SPARSE_DOT_PRODUCT_ERR_CONVERGENCE_FAIL: return "Numerical algorithm failed to converge within limit";
        default: return "Unrecognized error code";
    }
}
