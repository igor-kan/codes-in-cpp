/**
 * @file types.cpp
 * @brief Core types and configuration for Cacheline-Aligned CSR Sparse Matrix View with Vectorization.
 * Module: simd_csr_matrix_view
 */

#ifndef SIMD_CSR_MATRIX_VIEW_TYPES_H
#define SIMD_CSR_MATRIX_VIEW_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SIMD_CSR_MATRIX_VIEW_ALIGNMENT 64
#define SIMD_CSR_MATRIX_VIEW_DEFAULT_SZ 8192

typedef struct simd_csr_matrix_view_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} simd_csr_matrix_view_config_t;

typedef struct simd_csr_matrix_view_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    simd_csr_matrix_view_config_t config;
} simd_csr_matrix_view_state_t;

#endif /* SIMD_CSR_MATRIX_VIEW_TYPES_H */
