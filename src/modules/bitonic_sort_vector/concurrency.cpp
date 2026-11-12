/**
 * @file concurrency.cpp
 * @brief Thread-safe reentrancy and atomic state primitives for Parallel Bitonic Sorting Network for Array Blocks.
 * Module: bitonic_sort_vector
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct bitonic_sort_vector_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} bitonic_sort_vector_atomic_state_t;

static inline void bitonic_sort_vector_atomic_increment(bitonic_sort_vector_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
