/**
 * @file types.cpp
 * @brief Core types and configuration for Small Buffer Optimized Type-Erased Callable.
 * Module: type_erased_callable
 */

#ifndef TYPE_ERASED_CALLABLE_TYPES_H
#define TYPE_ERASED_CALLABLE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define TYPE_ERASED_CALLABLE_ALIGNMENT 64
#define TYPE_ERASED_CALLABLE_CAPACITY 2048

typedef struct type_erased_callable_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} type_erased_callable_config_t;

typedef struct type_erased_callable_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    type_erased_callable_config_t config;
} type_erased_callable_state_t;

#endif /* TYPE_ERASED_CALLABLE_TYPES_H */
