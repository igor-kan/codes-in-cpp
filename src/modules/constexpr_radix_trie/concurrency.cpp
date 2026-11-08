/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Compile-Time Prefix Radix Trie Router.
 * Module: constexpr_radix_trie
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct constexpr_radix_trie_atomic_counter {
    volatile uint64_t value;
} constexpr_radix_trie_atomic_counter_t;

static inline void constexpr_radix_trie_counter_inc(constexpr_radix_trie_atomic_counter_t* c) {
    __atomic_fetch_add(&c->value, 1, __ATOMIC_RELAXED);
}
