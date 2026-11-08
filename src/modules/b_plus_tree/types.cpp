/**
 * @file types.cpp
 * @brief Core type definitions and operational interfaces for Cacheline-Sized Node B+ Tree for Ordered Storage.
 * Module: b_plus_tree
 */

#ifndef B_PLUS_TREE_TYPES_H
#define B_PLUS_TREE_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define B_PLUS_TREE_ALIGNMENT 64
#define B_PLUS_TREE_SUCCESS 0
#define B_PLUS_TREE_ERR_NULL_PTR -1
#define B_PLUS_TREE_ERR_INVALID_PARAM -2
#define B_PLUS_TREE_ERR_OUT_OF_BOUNDS -3

typedef struct b_plus_tree_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} b_plus_tree_config_t;

typedef struct b_plus_tree_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    b_plus_tree_config_t config;
} b_plus_tree_context_t;

int b_plus_tree_init(b_plus_tree_context_t* ctx, const b_plus_tree_config_t* cfg);
int b_plus_tree_destroy(b_plus_tree_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* B_PLUS_TREE_TYPES_H */
