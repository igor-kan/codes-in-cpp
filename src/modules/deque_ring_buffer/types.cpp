/**
 * @file types.cpp
 * @brief Domain types, memory layouts, and configurations for Cacheline-Aligned Circular Deque with Modulo Wrap.
 * Module: deque_ring_buffer | Algorithm Family: ring_buffer
 */

#ifndef DEQUE_RING_BUFFER_TYPES_H
#define DEQUE_RING_BUFFER_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define DEQUE_RING_BUFFER_ALIGNMENT 64
#define DEQUE_RING_BUFFER_CAPACITY 2048

typedef struct deque_ring_buffer_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} deque_ring_buffer_config_t;

typedef struct deque_ring_buffer_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    deque_ring_buffer_config_t config;
} deque_ring_buffer_state_t;

#endif /* DEQUE_RING_BUFFER_TYPES_H */
