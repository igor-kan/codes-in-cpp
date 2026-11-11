/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Cooperative Fiber Scheduler with Work-Stealing Queues.
 * Module: actor_fiber_scheduler
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct actor_fiber_scheduler_sync_counter {
    volatile uint64_t count;
} actor_fiber_scheduler_sync_counter_t;

static inline void actor_fiber_scheduler_sync_inc_v47(actor_fiber_scheduler_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
