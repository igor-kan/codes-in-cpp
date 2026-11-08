/**
 * @file types.cpp
 * @brief Core type definitions and operational interfaces for Strided Multi-Dimensional Tensor View with SIMD Alignment.
 * Module: simd_tensor_view
 */

#ifndef SIMD_TENSOR_VIEW_TYPES_H
#define SIMD_TENSOR_VIEW_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SIMD_TENSOR_VIEW_ALIGNMENT 64
#define SIMD_TENSOR_VIEW_SUCCESS 0
#define SIMD_TENSOR_VIEW_ERR_NULL_PTR -1
#define SIMD_TENSOR_VIEW_ERR_INVALID_PARAM -2
#define SIMD_TENSOR_VIEW_ERR_OUT_OF_BOUNDS -3

typedef struct simd_tensor_view_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} simd_tensor_view_config_t;

typedef struct simd_tensor_view_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    simd_tensor_view_config_t config;
} simd_tensor_view_context_t;

int simd_tensor_view_init(simd_tensor_view_context_t* ctx, const simd_tensor_view_config_t* cfg);
int simd_tensor_view_destroy(simd_tensor_view_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* SIMD_TENSOR_VIEW_TYPES_H */
