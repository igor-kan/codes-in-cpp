/**
 * @file interface.cpp
 * @brief Abstract function prototypes and contracts for Parallel Bitonic Sorting Network for Array Blocks.
 * Module: bitonic_sort_vector | Algorithm Family: sorting
 */

#ifndef BITONIC_SORT_VECTOR_INTERFACE_H
#define BITONIC_SORT_VECTOR_INTERFACE_H

#include "types.cpp"

typedef int (*bitonic_sort_vector_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct bitonic_sort_vector_vtable {
    int (*init)(bitonic_sort_vector_state_t* state, const bitonic_sort_vector_config_t* cfg);
    int (*execute)(bitonic_sort_vector_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(bitonic_sort_vector_state_t* state);
    int (*destroy)(bitonic_sort_vector_state_t* state);
} bitonic_sort_vector_vtable_t;

#endif /* BITONIC_SORT_VECTOR_INTERFACE_H */
