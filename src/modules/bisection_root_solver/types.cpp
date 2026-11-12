/**
 * @file types.cpp
 * @brief Domain types, memory layouts, and configurations for Continuous Bisection Root-Finding Bracketing Engine.
 * Module: bisection_root_solver | Algorithm Family: root_finding
 */

#ifndef BISECTION_ROOT_SOLVER_TYPES_H
#define BISECTION_ROOT_SOLVER_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define BISECTION_ROOT_SOLVER_ALIGNMENT 64
#define BISECTION_ROOT_SOLVER_BASE_CAPACITY 1024

typedef struct bisection_root_solver_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} bisection_root_solver_config_t;

typedef struct bisection_root_solver_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    bisection_root_solver_config_t config;
} bisection_root_solver_state_t;

#endif /* BISECTION_ROOT_SOLVER_TYPES_H */
