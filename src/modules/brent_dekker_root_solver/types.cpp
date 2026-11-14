/**
 * @file types.cpp
 * @brief Domain types, memory layouts, and configurations for Brent-Dekker Hybrid Root Finder Combining Bisection.
 * Module: brent_dekker_root_solver | Algorithm Family: root_finding
 */

#ifndef BRENT_DEKKER_ROOT_SOLVER_TYPES_H
#define BRENT_DEKKER_ROOT_SOLVER_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define BRENT_DEKKER_ROOT_SOLVER_ALIGNMENT 64
#define BRENT_DEKKER_ROOT_SOLVER_CAPACITY 4096

typedef struct brent_dekker_root_solver_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} brent_dekker_root_solver_config_t;

typedef struct brent_dekker_root_solver_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    brent_dekker_root_solver_config_t config;
} brent_dekker_root_solver_state_t;

#endif /* BRENT_DEKKER_ROOT_SOLVER_TYPES_H */
