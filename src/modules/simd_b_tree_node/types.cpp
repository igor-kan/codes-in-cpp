/**
 * @file types.cpp
 * @brief Core types and configuration for Cacheline-Aligned B-Tree Node with SIMD Search.
 * Module: simd_b_tree_node
 */

#ifndef SIMD_B_TREE_NODE_TYPES_H
#define SIMD_B_TREE_NODE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SIMD_B_TREE_NODE_ALIGNMENT 64
#define SIMD_B_TREE_NODE_CAPACITY 4096

typedef struct simd_b_tree_node_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} simd_b_tree_node_config_t;

typedef struct simd_b_tree_node_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    simd_b_tree_node_config_t config;
} simd_b_tree_node_state_t;

#endif /* SIMD_B_TREE_NODE_TYPES_H */
