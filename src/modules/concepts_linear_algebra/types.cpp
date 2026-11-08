/**
 * @file types.cpp
 * @brief Core type definitions and operational interfaces for C++20 Concept Constraints for Algebraic Vector Spaces.
 * Module: concepts_linear_algebra
 */

#ifndef CONCEPTS_LINEAR_ALGEBRA_TYPES_H
#define CONCEPTS_LINEAR_ALGEBRA_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define CONCEPTS_LINEAR_ALGEBRA_ALIGNMENT 64
#define CONCEPTS_LINEAR_ALGEBRA_SUCCESS 0
#define CONCEPTS_LINEAR_ALGEBRA_ERR_NULL_PTR -1
#define CONCEPTS_LINEAR_ALGEBRA_ERR_INVALID_PARAM -2
#define CONCEPTS_LINEAR_ALGEBRA_ERR_OUT_OF_BOUNDS -3

typedef struct concepts_linear_algebra_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} concepts_linear_algebra_config_t;

typedef struct concepts_linear_algebra_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    concepts_linear_algebra_config_t config;
} concepts_linear_algebra_context_t;

int concepts_linear_algebra_init(concepts_linear_algebra_context_t* ctx, const concepts_linear_algebra_config_t* cfg);
int concepts_linear_algebra_destroy(concepts_linear_algebra_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* CONCEPTS_LINEAR_ALGEBRA_TYPES_H */
