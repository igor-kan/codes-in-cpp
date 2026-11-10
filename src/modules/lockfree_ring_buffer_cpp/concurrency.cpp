/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Cache-Aligned Lock-Free Ring Buffer with Acquire-Release.
 * Module: lockfree_ring_buffer_cpp
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct lockfree_ring_buffer_cpp_sync_counter {
    volatile uint64_t count;
} lockfree_ring_buffer_cpp_sync_counter_t;

static inline void lockfree_ring_buffer_cpp_sync_inc(lockfree_ring_buffer_cpp_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
