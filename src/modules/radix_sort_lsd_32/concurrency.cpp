/**
 * @file concurrency.cpp
 * @brief Thread-safe reentrancy and atomic state primitives for LSD 32-Bit Integer Radix Sort with Bucket Passes.
 * Module: radix_sort_lsd_32
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct radix_sort_lsd_32_reentrant_lock {
    volatile uint64_t sequence;
    volatile uint32_t concurrency_count;
} radix_sort_lsd_32_reentrant_lock_t;

static inline void radix_sort_lsd_32_seq_advance(radix_sort_lsd_32_reentrant_lock_t* lk) {
    __atomic_fetch_add(&lk->sequence, 1, __ATOMIC_RELEASE);
}
