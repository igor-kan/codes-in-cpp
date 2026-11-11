/**
 * @file types.cpp
 * @brief Core types and configuration for Adaptive Radix Tree (ART) with Path Compression.
 * Module: radix_tree_adaptive
 */

#ifndef RADIX_TREE_ADAPTIVE_TYPES_H
#define RADIX_TREE_ADAPTIVE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define RADIX_TREE_ADAPTIVE_ALIGNMENT 64
#define RADIX_TREE_ADAPTIVE_DEFAULT_SZ 8192

typedef struct radix_tree_adaptive_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} radix_tree_adaptive_config_t;

typedef struct radix_tree_adaptive_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    radix_tree_adaptive_config_t config;
} radix_tree_adaptive_state_t;

#endif /* RADIX_TREE_ADAPTIVE_TYPES_H */
