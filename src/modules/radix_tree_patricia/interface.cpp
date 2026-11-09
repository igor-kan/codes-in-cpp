/**
 * @file interface.cpp
 * @brief Abstract contracts and prototypes for Compact Patricia Trie with Bitwise Prefix Match.
 * Module: radix_tree_patricia
 */

#ifndef RADIX_TREE_PATRICIA_INTERFACE_H
#define RADIX_TREE_PATRICIA_INTERFACE_H

#include "types.cpp"

typedef int (*radix_tree_patricia_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct radix_tree_patricia_vtable {
    int (*init)(radix_tree_patricia_state_t* state, const radix_tree_patricia_config_t* cfg);
    int (*execute)(radix_tree_patricia_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(radix_tree_patricia_state_t* state);
} radix_tree_patricia_vtable_t;

#endif /* RADIX_TREE_PATRICIA_INTERFACE_H */
