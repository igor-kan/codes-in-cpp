/**
 * @file types.cpp
 * @brief Core type definitions and operational interfaces for Preconditioned Conjugate Gradient Sparse Linear Solver.
 * Module: conjugate_gradient
 */

#ifndef CONJUGATE_GRADIENT_TYPES_H
#define CONJUGATE_GRADIENT_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CONJUGATE_GRADIENT_ALIGNMENT 64
#define CONJUGATE_GRADIENT_SUCCESS 0
#define CONJUGATE_GRADIENT_ERR_NULL_PTR -1
#define CONJUGATE_GRADIENT_ERR_INVALID_PARAM -2
#define CONJUGATE_GRADIENT_ERR_OUT_OF_BOUNDS -3

typedef struct conjugate_gradient_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} conjugate_gradient_config_t;

typedef struct conjugate_gradient_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    conjugate_gradient_config_t config;
} conjugate_gradient_context_t;

int conjugate_gradient_init(conjugate_gradient_context_t* ctx, const conjugate_gradient_config_t* cfg);
int conjugate_gradient_destroy(conjugate_gradient_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* CONJUGATE_GRADIENT_TYPES_H */
