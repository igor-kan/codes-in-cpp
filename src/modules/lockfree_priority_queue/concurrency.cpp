/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Bounded Lock-Free Priority Queue with Atomic SkipList.
 * Module: lockfree_priority_queue
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct lockfree_priority_queue_sync_counter {
    volatile uint64_t count;
} lockfree_priority_queue_sync_counter_t;

static inline void lockfree_priority_queue_sync_inc_v47(lockfree_priority_queue_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
