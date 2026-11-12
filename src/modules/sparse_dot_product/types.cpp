/**
 * @file types.cpp
 * @brief Domain types, memory layouts, and configurations for Two-Pointer Sparse Compressed Vector Inner Product.
 * Module: sparse_dot_product | Algorithm Family: sparse_math
 */

#ifndef SPARSE_DOT_PRODUCT_TYPES_H
#define SPARSE_DOT_PRODUCT_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SPARSE_DOT_PRODUCT_ALIGNMENT 64
#define SPARSE_DOT_PRODUCT_BASE_CAPACITY 1024

typedef struct sparse_dot_product_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} sparse_dot_product_config_t;

typedef struct sparse_dot_product_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    sparse_dot_product_config_t config;
} sparse_dot_product_state_t;

#endif /* SPARSE_DOT_PRODUCT_TYPES_H */
