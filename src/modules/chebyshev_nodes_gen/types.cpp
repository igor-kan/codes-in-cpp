/**
 * @file types.cpp
 * @brief Domain types, memory layouts, and configurations for Chebyshev-Gauss Roots and Extrema Node Generator.
 * Module: chebyshev_nodes_gen | Algorithm Family: collocation
 */

#ifndef CHEBYSHEV_NODES_GEN_TYPES_H
#define CHEBYSHEV_NODES_GEN_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define CHEBYSHEV_NODES_GEN_ALIGNMENT 64
#define CHEBYSHEV_NODES_GEN_CAPACITY 4096

typedef struct chebyshev_nodes_gen_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} chebyshev_nodes_gen_config_t;

typedef struct chebyshev_nodes_gen_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    chebyshev_nodes_gen_config_t config;
} chebyshev_nodes_gen_state_t;

#endif /* CHEBYSHEV_NODES_GEN_TYPES_H */
