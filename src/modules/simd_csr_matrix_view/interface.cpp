/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for Cacheline-Aligned CSR Sparse Matrix View with Vectorization.
 * Module: simd_csr_matrix_view
 */

#ifndef SIMD_CSR_MATRIX_VIEW_INTERFACE_H
#define SIMD_CSR_MATRIX_VIEW_INTERFACE_H

#include "types.cpp"

typedef int (*simd_csr_matrix_view_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct simd_csr_matrix_view_vtable {
    int (*init)(simd_csr_matrix_view_state_t* state, const simd_csr_matrix_view_config_t* cfg);
    int (*execute)(simd_csr_matrix_view_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(simd_csr_matrix_view_state_t* state);
    int (*destroy)(simd_csr_matrix_view_state_t* state);
} simd_csr_matrix_view_vtable_t;

#endif /* SIMD_CSR_MATRIX_VIEW_INTERFACE_H */
