/**
 * @file types.cpp
 * @brief Domain types, memory layouts, and configurations for Most Significant Digit (MSD) Recursive Radix Sort.
 * Module: radix_sort_msd_vector | Algorithm Family: sorting
 */

#ifndef RADIX_SORT_MSD_VECTOR_TYPES_H
#define RADIX_SORT_MSD_VECTOR_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define RADIX_SORT_MSD_VECTOR_ALIGNMENT 64
#define RADIX_SORT_MSD_VECTOR_CAPACITY 4096

typedef struct radix_sort_msd_vector_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} radix_sort_msd_vector_config_t;

typedef struct radix_sort_msd_vector_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    radix_sort_msd_vector_config_t config;
} radix_sort_msd_vector_state_t;

#endif /* RADIX_SORT_MSD_VECTOR_TYPES_H */
