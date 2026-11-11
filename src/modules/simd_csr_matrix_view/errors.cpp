/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for Cacheline-Aligned CSR Sparse Matrix View with Vectorization.
 * Module: simd_csr_matrix_view
 */

typedef enum simd_csr_matrix_view_error_code {
    SIMD_CSR_MATRIX_VIEW_STATUS_OK = 0,
    SIMD_CSR_MATRIX_VIEW_ERR_NULL_PTR = -20,
    SIMD_CSR_MATRIX_VIEW_ERR_OUT_OF_BOUNDS = -21,
    SIMD_CSR_MATRIX_VIEW_ERR_DIVERGENCE = -22
} simd_csr_matrix_view_error_code_t;

const char* simd_csr_matrix_view_error_message(simd_csr_matrix_view_error_code_t code) {
    switch (code) {
        case SIMD_CSR_MATRIX_VIEW_STATUS_OK: return "Operational success";
        case SIMD_CSR_MATRIX_VIEW_ERR_NULL_PTR: return "Null pointer argument";
        case SIMD_CSR_MATRIX_VIEW_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case SIMD_CSR_MATRIX_VIEW_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
