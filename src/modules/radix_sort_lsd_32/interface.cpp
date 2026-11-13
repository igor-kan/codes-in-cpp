/**
 * @file interface.cpp
 * @brief Abstract function prototypes and contracts for LSD 32-Bit Integer Radix Sort with Bucket Passes.
 * Module: radix_sort_lsd_32 | Algorithm Family: sorting
 */

#ifndef RADIX_SORT_LSD_32_INTERFACE_H
#define RADIX_SORT_LSD_32_INTERFACE_H

#include "types.cpp"

typedef int (*radix_sort_lsd_32_kernel_fn)(const double* in_vec, double* out_vec, size_t n);

typedef struct radix_sort_lsd_32_vtable {
    int (*init)(radix_sort_lsd_32_state_t* state, const radix_sort_lsd_32_config_t* cfg);
    int (*execute)(radix_sort_lsd_32_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(radix_sort_lsd_32_state_t* state);
    int (*destroy)(radix_sort_lsd_32_state_t* state);
} radix_sort_lsd_32_vtable_t;

#endif /* RADIX_SORT_LSD_32_INTERFACE_H */
