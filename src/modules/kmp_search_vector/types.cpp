/**
 * @file types.cpp
 * @brief Domain types, memory layouts, and configurations for Knuth-Morris-Pratt Substring Matcher using LPS Table.
 * Module: kmp_search_vector | Algorithm Family: string_search
 */

#ifndef KMP_SEARCH_VECTOR_TYPES_H
#define KMP_SEARCH_VECTOR_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define KMP_SEARCH_VECTOR_ALIGNMENT 64
#define KMP_SEARCH_VECTOR_CAPACITY 4096

typedef struct kmp_search_vector_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} kmp_search_vector_config_t;

typedef struct kmp_search_vector_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    kmp_search_vector_config_t config;
} kmp_search_vector_state_t;

#endif /* KMP_SEARCH_VECTOR_TYPES_H */
