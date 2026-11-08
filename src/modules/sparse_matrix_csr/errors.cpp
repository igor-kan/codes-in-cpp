/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for Compressed Sparse Row Matrix SpMV Acceleration.
 * Module: sparse_matrix_csr
 */

typedef enum sparse_matrix_csr_error {
    SPARSE_MATRIX_CSR_OK = 0,
    SPARSE_MATRIX_CSR_ERR_NULL = -100,
    SPARSE_MATRIX_CSR_ERR_CAPACITY = -101,
    SPARSE_MATRIX_CSR_ERR_CONVERGENCE = -102
} sparse_matrix_csr_error_t;

const char* sparse_matrix_csr_strerror(sparse_matrix_csr_error_t err) {
    switch (err) {
        case SPARSE_MATRIX_CSR_OK: return "Success";
        case SPARSE_MATRIX_CSR_ERR_NULL: return "Encountered null pointer argument";
        case SPARSE_MATRIX_CSR_ERR_CAPACITY: return "Capacity limit exceeded";
        case SPARSE_MATRIX_CSR_ERR_CONVERGENCE: return "Numerical algorithm failed to converge";
        default: return "Unknown error";
    }
}
