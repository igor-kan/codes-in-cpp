/**
 * @file interface.cpp
 * @brief Abstract function prototypes and contracts for Most Significant Digit (MSD) Recursive Radix Sort.
 * Module: radix_sort_msd_vector | Algorithm Family: sorting
 */

#ifndef RADIX_SORT_MSD_VECTOR_INTERFACE_H
#define RADIX_SORT_MSD_VECTOR_INTERFACE_H

#include "types.cpp"

typedef int (*radix_sort_msd_vector_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct radix_sort_msd_vector_vtable {
    int (*init)(radix_sort_msd_vector_state_t* state, const radix_sort_msd_vector_config_t* cfg);
    int (*execute)(radix_sort_msd_vector_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(radix_sort_msd_vector_state_t* state);
    int (*destroy)(radix_sort_msd_vector_state_t* state);
} radix_sort_msd_vector_vtable_t;

#endif /* RADIX_SORT_MSD_VECTOR_INTERFACE_H */
