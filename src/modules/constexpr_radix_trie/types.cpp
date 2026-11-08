/**
 * @file types.cpp
 * @brief Core types and configuration for Compile-Time Prefix Radix Trie Router.
 * Module: constexpr_radix_trie
 */

#ifndef CONSTEXPR_RADIX_TRIE_TYPES_H
#define CONSTEXPR_RADIX_TRIE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define CONSTEXPR_RADIX_TRIE_ALIGNMENT 64
#define CONSTEXPR_RADIX_TRIE_DEFAULT_CAPACITY 1024

typedef struct constexpr_radix_trie_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} constexpr_radix_trie_config_t;

typedef struct constexpr_radix_trie_state {
    void* memory_arena;
    size_t count;
    uint64_t metric_cycles;
    constexpr_radix_trie_config_t config;
} constexpr_radix_trie_state_t;

#endif /* CONSTEXPR_RADIX_TRIE_TYPES_H */
