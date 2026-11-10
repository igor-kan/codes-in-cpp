/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Cacheline-Aligned B-Tree Node with SIMD Search.
 * Module: simd_b_tree_node
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct simd_b_tree_node_sync_counter {
    volatile uint64_t count;
} simd_b_tree_node_sync_counter_t;

static inline void simd_b_tree_node_sync_inc(simd_b_tree_node_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
