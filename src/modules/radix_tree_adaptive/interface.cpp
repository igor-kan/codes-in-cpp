/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for Adaptive Radix Tree (ART) with Path Compression.
 * Module: radix_tree_adaptive
 */

#ifndef RADIX_TREE_ADAPTIVE_INTERFACE_H
#define RADIX_TREE_ADAPTIVE_INTERFACE_H

#include "types.cpp"

typedef int (*radix_tree_adaptive_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct radix_tree_adaptive_vtable {
    int (*init)(radix_tree_adaptive_state_t* state, const radix_tree_adaptive_config_t* cfg);
    int (*execute)(radix_tree_adaptive_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(radix_tree_adaptive_state_t* state);
    int (*destroy)(radix_tree_adaptive_state_t* state);
} radix_tree_adaptive_vtable_t;

#endif /* RADIX_TREE_ADAPTIVE_INTERFACE_H */
