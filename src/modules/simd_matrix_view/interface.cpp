/**
 * @file interface.cpp
 * @brief Abstract contracts and prototypes for Padded 2D Strided Matrix View with Vectorization.
 * Module: simd_matrix_view
 */

#ifndef SIMD_MATRIX_VIEW_INTERFACE_H
#define SIMD_MATRIX_VIEW_INTERFACE_H

#include "types.cpp"

typedef int (*simd_matrix_view_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct simd_matrix_view_vtable {
    int (*init)(simd_matrix_view_state_t* state, const simd_matrix_view_config_t* cfg);
    int (*execute)(simd_matrix_view_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(simd_matrix_view_state_t* state);
} simd_matrix_view_vtable_t;

#endif /* SIMD_MATRIX_VIEW_INTERFACE_H */
