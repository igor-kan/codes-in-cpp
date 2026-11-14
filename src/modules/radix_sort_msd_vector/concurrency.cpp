/**
 * @file concurrency.cpp
 * @brief Thread-safe reentrancy and atomic state primitives for Most Significant Digit (MSD) Recursive Radix Sort.
 * Module: radix_sort_msd_vector
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct radix_sort_msd_vector_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} radix_sort_msd_vector_sync_state_t;

static inline void radix_sort_msd_vector_sync_increment(radix_sort_msd_vector_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
