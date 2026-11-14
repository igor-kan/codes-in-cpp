/**
 * @file interface.cpp
 * @brief Abstract function prototypes and contracts for Compressed Sparse Column (CSC) Matrix-Vector Transpose.
 * Module: compressed_sparse_col | Algorithm Family: sparse_math
 */

#ifndef COMPRESSED_SPARSE_COL_INTERFACE_H
#define COMPRESSED_SPARSE_COL_INTERFACE_H

#include "types.cpp"

typedef int (*compressed_sparse_col_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct compressed_sparse_col_vtable {
    int (*init)(compressed_sparse_col_state_t* state, const compressed_sparse_col_config_t* cfg);
    int (*execute)(compressed_sparse_col_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(compressed_sparse_col_state_t* state);
    int (*destroy)(compressed_sparse_col_state_t* state);
} compressed_sparse_col_vtable_t;

#endif /* COMPRESSED_SPARSE_COL_INTERFACE_H */
