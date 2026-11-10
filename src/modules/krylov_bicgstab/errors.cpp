/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for Preconditioned BiCGSTAB Sparse Linear System Solver.
 * Module: krylov_bicgstab
 */

typedef enum krylov_bicgstab_error_code {
    KRYLOV_BICGSTAB_STATUS_OK = 0,
    KRYLOV_BICGSTAB_ERR_NULL_PTR = -10,
    KRYLOV_BICGSTAB_ERR_OUT_OF_BOUNDS = -11,
    KRYLOV_BICGSTAB_ERR_DIVERGENCE = -12
} krylov_bicgstab_error_code_t;

const char* krylov_bicgstab_error_message(krylov_bicgstab_error_code_t code) {
    switch (code) {
        case KRYLOV_BICGSTAB_STATUS_OK: return "Operational success";
        case KRYLOV_BICGSTAB_ERR_NULL_PTR: return "Null pointer argument";
        case KRYLOV_BICGSTAB_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case KRYLOV_BICGSTAB_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
