/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Cacheline-Aligned Lock-Free SPSC Queue.
 * Module: lockfree_spsc_queue
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct lockfree_spsc_queue_atomic_counter {
    volatile uint64_t value;
} lockfree_spsc_queue_atomic_counter_t;

static inline void lockfree_spsc_queue_counter_inc(lockfree_spsc_queue_atomic_counter_t* c) {
    __atomic_fetch_add(&c->value, 1, __ATOMIC_RELAXED);
}
