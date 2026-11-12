/**
 * @file types.cpp
 * @brief Domain types, memory layouts, and configurations for Boyer-Moore Bad-Character Substring Locator.
 * Module: boyer_moore_search | Algorithm Family: string_search
 */

#ifndef BOYER_MOORE_SEARCH_TYPES_H
#define BOYER_MOORE_SEARCH_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define BOYER_MOORE_SEARCH_ALIGNMENT 64
#define BOYER_MOORE_SEARCH_BASE_CAPACITY 1024

typedef struct boyer_moore_search_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} boyer_moore_search_config_t;

typedef struct boyer_moore_search_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    boyer_moore_search_config_t config;
} boyer_moore_search_state_t;

#endif /* BOYER_MOORE_SEARCH_TYPES_H */
