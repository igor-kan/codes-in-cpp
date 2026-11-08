/**
 * @file types.cpp
 * @brief Core types and configuration for Cacheline-Aligned Lock-Free SPSC Queue.
 * Module: lockfree_spsc_queue
 */

#ifndef LOCKFREE_SPSC_QUEUE_TYPES_H
#define LOCKFREE_SPSC_QUEUE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define LOCKFREE_SPSC_QUEUE_ALIGNMENT 64
#define LOCKFREE_SPSC_QUEUE_DEFAULT_CAPACITY 1024

typedef struct lockfree_spsc_queue_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} lockfree_spsc_queue_config_t;

typedef struct lockfree_spsc_queue_state {
    void* memory_arena;
    size_t count;
    uint64_t metric_cycles;
    lockfree_spsc_queue_config_t config;
} lockfree_spsc_queue_state_t;

#endif /* LOCKFREE_SPSC_QUEUE_TYPES_H */
