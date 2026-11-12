/**
 * @file interface.cpp
 * @brief Abstract function prototypes and contracts for Two-Pointer Sparse Compressed Vector Inner Product.
 * Module: sparse_dot_product | Algorithm Family: sparse_math
 */

#ifndef SPARSE_DOT_PRODUCT_INTERFACE_H
#define SPARSE_DOT_PRODUCT_INTERFACE_H

#include "types.cpp"

typedef int (*sparse_dot_product_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct sparse_dot_product_vtable {
    int (*init)(sparse_dot_product_state_t* state, const sparse_dot_product_config_t* cfg);
    int (*execute)(sparse_dot_product_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(sparse_dot_product_state_t* state);
    int (*destroy)(sparse_dot_product_state_t* state);
} sparse_dot_product_vtable_t;

#endif /* SPARSE_DOT_PRODUCT_INTERFACE_H */
