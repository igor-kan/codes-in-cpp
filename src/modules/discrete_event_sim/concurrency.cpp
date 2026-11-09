/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Priority-Queue Discrete Event Simulation Engine.
 * Module: discrete_event_sim
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct discrete_event_sim_sync_counter {
    volatile uint64_t count;
} discrete_event_sim_sync_counter_t;

static inline void discrete_event_sim_sync_inc(discrete_event_sim_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
