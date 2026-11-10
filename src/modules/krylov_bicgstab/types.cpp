/**
 * @file types.cpp
 * @brief Core types and configuration for Preconditioned BiCGSTAB Sparse Linear System Solver.
 * Module: krylov_bicgstab
 */

#ifndef KRYLOV_BICGSTAB_TYPES_H
#define KRYLOV_BICGSTAB_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define KRYLOV_BICGSTAB_ALIGNMENT 64
#define KRYLOV_BICGSTAB_CAPACITY 4096

typedef struct krylov_bicgstab_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} krylov_bicgstab_config_t;

typedef struct krylov_bicgstab_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    krylov_bicgstab_config_t config;
} krylov_bicgstab_state_t;

#endif /* KRYLOV_BICGSTAB_TYPES_H */
