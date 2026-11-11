/**
 * @file types.cpp
 * @brief Core types and configuration for Bounded Lock-Free Priority Queue with Atomic SkipList.
 * Module: lockfree_priority_queue
 */

#ifndef LOCKFREE_PRIORITY_QUEUE_TYPES_H
#define LOCKFREE_PRIORITY_QUEUE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define LOCKFREE_PRIORITY_QUEUE_ALIGNMENT 64
#define LOCKFREE_PRIORITY_QUEUE_DEFAULT_SZ 8192

typedef struct lockfree_priority_queue_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} lockfree_priority_queue_config_t;

typedef struct lockfree_priority_queue_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    lockfree_priority_queue_config_t config;
} lockfree_priority_queue_state_t;

#endif /* LOCKFREE_PRIORITY_QUEUE_TYPES_H */
