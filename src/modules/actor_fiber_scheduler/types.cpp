/**
 * @file types.cpp
 * @brief Core types and configuration for Cooperative Fiber Scheduler with Work-Stealing Queues.
 * Module: actor_fiber_scheduler
 */

#ifndef ACTOR_FIBER_SCHEDULER_TYPES_H
#define ACTOR_FIBER_SCHEDULER_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define ACTOR_FIBER_SCHEDULER_ALIGNMENT 64
#define ACTOR_FIBER_SCHEDULER_DEFAULT_SZ 8192

typedef struct actor_fiber_scheduler_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} actor_fiber_scheduler_config_t;

typedef struct actor_fiber_scheduler_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    actor_fiber_scheduler_config_t config;
} actor_fiber_scheduler_state_t;

#endif /* ACTOR_FIBER_SCHEDULER_TYPES_H */
