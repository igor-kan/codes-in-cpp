/**
 * @file types.cpp
 * @brief Core types and configuration for Compressed Sparse Row Matrix SpMV Acceleration.
 * Module: sparse_matrix_csr
 */

#ifndef SPARSE_MATRIX_CSR_TYPES_H
#define SPARSE_MATRIX_CSR_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SPARSE_MATRIX_CSR_ALIGNMENT 64
#define SPARSE_MATRIX_CSR_DEFAULT_CAPACITY 1024

typedef struct sparse_matrix_csr_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} sparse_matrix_csr_config_t;

typedef struct sparse_matrix_csr_state {
    void* memory_arena;
    size_t count;
    uint64_t metric_cycles;
    sparse_matrix_csr_config_t config;
} sparse_matrix_csr_state_t;

#endif /* SPARSE_MATRIX_CSR_TYPES_H */
