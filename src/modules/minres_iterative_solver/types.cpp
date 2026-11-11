/**
 * @file types.cpp
 * @brief Core types and configuration for Minimal Residual (MINRES) Symmetric Indefinite Solver.
 * Module: minres_iterative_solver
 */

#ifndef MINRES_ITERATIVE_SOLVER_TYPES_H
#define MINRES_ITERATIVE_SOLVER_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define MINRES_ITERATIVE_SOLVER_ALIGNMENT 64
#define MINRES_ITERATIVE_SOLVER_DEFAULT_SZ 8192

typedef struct minres_iterative_solver_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} minres_iterative_solver_config_t;

typedef struct minres_iterative_solver_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    minres_iterative_solver_config_t config;
} minres_iterative_solver_state_t;

#endif /* MINRES_ITERATIVE_SOLVER_TYPES_H */
