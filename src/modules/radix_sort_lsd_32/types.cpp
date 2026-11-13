/**
 * @file types.cpp
 * @brief Domain types, memory layouts, and configurations for LSD 32-Bit Integer Radix Sort with Bucket Passes.
 * Module: radix_sort_lsd_32 | Algorithm Family: sorting
 */

#ifndef RADIX_SORT_LSD_32_TYPES_H
#define RADIX_SORT_LSD_32_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define RADIX_SORT_LSD_32_ALIGNMENT 64
#define RADIX_SORT_LSD_32_CAPACITY 2048

typedef struct radix_sort_lsd_32_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} radix_sort_lsd_32_config_t;

typedef struct radix_sort_lsd_32_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    radix_sort_lsd_32_config_t config;
} radix_sort_lsd_32_state_t;

#endif /* RADIX_SORT_LSD_32_TYPES_H */
