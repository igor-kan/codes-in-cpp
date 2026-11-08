/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for Compressed Sparse Row Matrix SpMV Acceleration.
 * Module: sparse_matrix_csr
 */

#ifndef SPARSE_MATRIX_CSR_INTERFACE_H
#define SPARSE_MATRIX_CSR_INTERFACE_H

#include "types.cpp"

typedef int (*sparse_matrix_csr_transform_fn)(const double* in_data, double* out_data, size_t n);

typedef struct sparse_matrix_csr_interface {
    int (*init)(sparse_matrix_csr_state_t* state, const sparse_matrix_csr_config_t* cfg);
    int (*execute)(sparse_matrix_csr_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(sparse_matrix_csr_state_t* state);
    int (*destroy)(sparse_matrix_csr_state_t* state);
} sparse_matrix_csr_interface_t;

#endif /* SPARSE_MATRIX_CSR_INTERFACE_H */
