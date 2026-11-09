/**
 * @file types.cpp
 * @brief Core types and configuration for Padded 2D Strided Matrix View with Vectorization.
 * Module: simd_matrix_view
 */

#ifndef SIMD_MATRIX_VIEW_TYPES_H
#define SIMD_MATRIX_VIEW_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define SIMD_MATRIX_VIEW_ALIGNMENT 64
#define SIMD_MATRIX_VIEW_CAPACITY 2048

typedef struct simd_matrix_view_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} simd_matrix_view_config_t;

typedef struct simd_matrix_view_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    simd_matrix_view_config_t config;
} simd_matrix_view_state_t;

#endif /* SIMD_MATRIX_VIEW_TYPES_H */
