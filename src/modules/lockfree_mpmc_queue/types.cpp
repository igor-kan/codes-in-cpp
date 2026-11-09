/**
 * @file types.cpp
 * @brief Core types and configuration for Bounded Multi-Producer Multi-Consumer Queue.
 * Module: lockfree_mpmc_queue
 */

#ifndef LOCKFREE_MPMC_QUEUE_TYPES_H
#define LOCKFREE_MPMC_QUEUE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define LOCKFREE_MPMC_QUEUE_ALIGNMENT 64
#define LOCKFREE_MPMC_QUEUE_CAPACITY 2048

typedef struct lockfree_mpmc_queue_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} lockfree_mpmc_queue_config_t;

typedef struct lockfree_mpmc_queue_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    lockfree_mpmc_queue_config_t config;
} lockfree_mpmc_queue_state_t;

#endif /* LOCKFREE_MPMC_QUEUE_TYPES_H */
