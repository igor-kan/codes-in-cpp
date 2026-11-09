/**
 * @file types.cpp
 * @brief Core types and configuration for Compact Patricia Trie with Bitwise Prefix Match.
 * Module: radix_tree_patricia
 */

#ifndef RADIX_TREE_PATRICIA_TYPES_H
#define RADIX_TREE_PATRICIA_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define RADIX_TREE_PATRICIA_ALIGNMENT 64
#define RADIX_TREE_PATRICIA_CAPACITY 2048

typedef struct radix_tree_patricia_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} radix_tree_patricia_config_t;

typedef struct radix_tree_patricia_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    radix_tree_patricia_config_t config;
} radix_tree_patricia_state_t;

#endif /* RADIX_TREE_PATRICIA_TYPES_H */
