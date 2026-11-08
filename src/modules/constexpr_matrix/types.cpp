/**
 * @file types.cpp
 * @brief Core type definitions and operational interfaces for Compile-Time Fixed-Size Dense Matrix with LU Solver.
 * Module: constexpr_matrix
 */

#ifndef CONSTEXPR_MATRIX_TYPES_H
#define CONSTEXPR_MATRIX_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CONSTEXPR_MATRIX_ALIGNMENT 64
#define CONSTEXPR_MATRIX_SUCCESS 0
#define CONSTEXPR_MATRIX_ERR_NULL_PTR -1
#define CONSTEXPR_MATRIX_ERR_INVALID_PARAM -2
#define CONSTEXPR_MATRIX_ERR_OUT_OF_BOUNDS -3

typedef struct constexpr_matrix_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} constexpr_matrix_config_t;

typedef struct constexpr_matrix_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    constexpr_matrix_config_t config;
} constexpr_matrix_context_t;

int constexpr_matrix_init(constexpr_matrix_context_t* ctx, const constexpr_matrix_config_t* cfg);
int constexpr_matrix_destroy(constexpr_matrix_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* CONSTEXPR_MATRIX_TYPES_H */
