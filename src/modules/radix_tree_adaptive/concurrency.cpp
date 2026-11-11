/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Adaptive Radix Tree (ART) with Path Compression.
 * Module: radix_tree_adaptive
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct radix_tree_adaptive_sync_counter {
    volatile uint64_t count;
} radix_tree_adaptive_sync_counter_t;

static inline void radix_tree_adaptive_sync_inc_v47(radix_tree_adaptive_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
