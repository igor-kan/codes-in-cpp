/**
 * @file types.cpp
 * @brief Core types and configuration for Cache-Aligned Lock-Free Ring Buffer with Acquire-Release.
 * Module: lockfree_ring_buffer_cpp
 */

#ifndef LOCKFREE_RING_BUFFER_CPP_TYPES_H
#define LOCKFREE_RING_BUFFER_CPP_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define LOCKFREE_RING_BUFFER_CPP_ALIGNMENT 64
#define LOCKFREE_RING_BUFFER_CPP_CAPACITY 4096

typedef struct lockfree_ring_buffer_cpp_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} lockfree_ring_buffer_cpp_config_t;

typedef struct lockfree_ring_buffer_cpp_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    lockfree_ring_buffer_cpp_config_t config;
} lockfree_ring_buffer_cpp_state_t;

#endif /* LOCKFREE_RING_BUFFER_CPP_TYPES_H */
