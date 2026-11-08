/**
 * @file types.cpp
 * @brief Core type definitions and operational interfaces for C++20 Coroutine Lazy Sequence Pipeline.
 * Module: coroutine_generator
 */

#ifndef COROUTINE_GENERATOR_TYPES_H
#define COROUTINE_GENERATOR_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define COROUTINE_GENERATOR_ALIGNMENT 64
#define COROUTINE_GENERATOR_SUCCESS 0
#define COROUTINE_GENERATOR_ERR_NULL_PTR -1
#define COROUTINE_GENERATOR_ERR_INVALID_PARAM -2
#define COROUTINE_GENERATOR_ERR_OUT_OF_BOUNDS -3

typedef struct coroutine_generator_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} coroutine_generator_config_t;

typedef struct coroutine_generator_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    coroutine_generator_config_t config;
} coroutine_generator_context_t;

int coroutine_generator_init(coroutine_generator_context_t* ctx, const coroutine_generator_config_t* cfg);
int coroutine_generator_destroy(coroutine_generator_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* COROUTINE_GENERATOR_TYPES_H */
