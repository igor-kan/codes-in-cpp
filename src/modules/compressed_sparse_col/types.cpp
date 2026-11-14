/**
 * @file types.cpp
 * @brief Domain types, memory layouts, and configurations for Compressed Sparse Column (CSC) Matrix-Vector Transpose.
 * Module: compressed_sparse_col | Algorithm Family: sparse_math
 */

#ifndef COMPRESSED_SPARSE_COL_TYPES_H
#define COMPRESSED_SPARSE_COL_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define COMPRESSED_SPARSE_COL_ALIGNMENT 64
#define COMPRESSED_SPARSE_COL_CAPACITY 4096

typedef struct compressed_sparse_col_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} compressed_sparse_col_config_t;

typedef struct compressed_sparse_col_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    compressed_sparse_col_config_t config;
} compressed_sparse_col_state_t;

#endif /* COMPRESSED_SPARSE_COL_TYPES_H */
