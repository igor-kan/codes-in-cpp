/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Bounded Multi-Producer Multi-Consumer Queue.
 * Module: lockfree_mpmc_queue
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct lockfree_mpmc_queue_sync_counter {
    volatile uint64_t count;
} lockfree_mpmc_queue_sync_counter_t;

static inline void lockfree_mpmc_queue_sync_inc(lockfree_mpmc_queue_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
