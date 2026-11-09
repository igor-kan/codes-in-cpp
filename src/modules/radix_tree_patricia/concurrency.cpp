/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Compact Patricia Trie with Bitwise Prefix Match.
 * Module: radix_tree_patricia
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct radix_tree_patricia_sync_counter {
    volatile uint64_t count;
} radix_tree_patricia_sync_counter_t;

static inline void radix_tree_patricia_sync_inc(radix_tree_patricia_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
