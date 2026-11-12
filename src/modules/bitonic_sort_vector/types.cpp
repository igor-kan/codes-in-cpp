/**
 * @file types.cpp
 * @brief Domain types, memory layouts, and configurations for Parallel Bitonic Sorting Network for Array Blocks.
 * Module: bitonic_sort_vector | Algorithm Family: sorting
 */

#ifndef BITONIC_SORT_VECTOR_TYPES_H
#define BITONIC_SORT_VECTOR_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define BITONIC_SORT_VECTOR_ALIGNMENT 64
#define BITONIC_SORT_VECTOR_BASE_CAPACITY 1024

typedef struct bitonic_sort_vector_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} bitonic_sort_vector_config_t;

typedef struct bitonic_sort_vector_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    bitonic_sort_vector_config_t config;
} bitonic_sort_vector_state_t;

#endif /* BITONIC_SORT_VECTOR_TYPES_H */
