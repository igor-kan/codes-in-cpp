/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for Cacheline-Aligned B-Tree Node with SIMD Search.
 * Module: simd_b_tree_node
 */

#ifndef SIMD_B_TREE_NODE_INTERFACE_H
#define SIMD_B_TREE_NODE_INTERFACE_H

#include "types.cpp"

typedef int (*simd_b_tree_node_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct simd_b_tree_node_vtable {
    int (*init)(simd_b_tree_node_state_t* state, const simd_b_tree_node_config_t* cfg);
    int (*execute)(simd_b_tree_node_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(simd_b_tree_node_state_t* state);
    int (*destroy)(simd_b_tree_node_state_t* state);
} simd_b_tree_node_vtable_t;

#endif /* SIMD_B_TREE_NODE_INTERFACE_H */
