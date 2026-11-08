/**
 * @file types.cpp
 * @brief Core type definitions and operational interfaces for Lock-Free Memory Reclamation via Hazard Pointers.
 * Module: atomic_hazard_pointer
 */

#ifndef ATOMIC_HAZARD_POINTER_TYPES_H
#define ATOMIC_HAZARD_POINTER_TYPES_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define ATOMIC_HAZARD_POINTER_ALIGNMENT 64
#define ATOMIC_HAZARD_POINTER_SUCCESS 0
#define ATOMIC_HAZARD_POINTER_ERR_NULL_PTR -1
#define ATOMIC_HAZARD_POINTER_ERR_INVALID_PARAM -2
#define ATOMIC_HAZARD_POINTER_ERR_OUT_OF_BOUNDS -3

typedef struct atomic_hazard_pointer_config {
    size_t capacity;
    uint32_t flags;
    double tolerance;
} atomic_hazard_pointer_config_t;

typedef struct atomic_hazard_pointer_context {
    void* buffer;
    size_t size;
    size_t capacity;
    uint64_t operations_count;
    atomic_hazard_pointer_config_t config;
} atomic_hazard_pointer_context_t;

int atomic_hazard_pointer_init(atomic_hazard_pointer_context_t* ctx, const atomic_hazard_pointer_config_t* cfg);
int atomic_hazard_pointer_destroy(atomic_hazard_pointer_context_t* ctx);

#ifdef __cplusplus
}
#endif

#endif /* ATOMIC_HAZARD_POINTER_TYPES_H */
