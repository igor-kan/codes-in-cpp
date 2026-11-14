/**
 * @file concurrency.cpp
 * @brief Thread-safe reentrancy and atomic state primitives for Knuth-Morris-Pratt Substring Matcher using LPS Table.
 * Module: kmp_search_vector
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct kmp_search_vector_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} kmp_search_vector_sync_state_t;

static inline void kmp_search_vector_sync_increment(kmp_search_vector_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
