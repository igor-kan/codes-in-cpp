/**
 * @file types.cpp
 * @brief Core types and configuration for Generalized Minimal Residual (GMRES) Sparse Solver.
 * Module: gmres_iterative_solver
 */

#ifndef GMRES_ITERATIVE_SOLVER_TYPES_H
#define GMRES_ITERATIVE_SOLVER_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define GMRES_ITERATIVE_SOLVER_ALIGNMENT 64
#define GMRES_ITERATIVE_SOLVER_CAPACITY 2048

typedef struct gmres_iterative_solver_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} gmres_iterative_solver_config_t;

typedef struct gmres_iterative_solver_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    gmres_iterative_solver_config_t config;
} gmres_iterative_solver_state_t;

#endif /* GMRES_ITERATIVE_SOLVER_TYPES_H */
