/**
 * @file types.cpp
 * @brief Domain types, memory layouts, and configurations for Gradient Descent Optimizer with Nesterov Momentum.
 * Module: gradient_descent_momentum | Algorithm Family: optimization
 */

#ifndef GRADIENT_DESCENT_MOMENTUM_TYPES_H
#define GRADIENT_DESCENT_MOMENTUM_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define GRADIENT_DESCENT_MOMENTUM_ALIGNMENT 64
#define GRADIENT_DESCENT_MOMENTUM_CAPACITY 2048

typedef struct gradient_descent_momentum_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} gradient_descent_momentum_config_t;

typedef struct gradient_descent_momentum_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    gradient_descent_momentum_config_t config;
} gradient_descent_momentum_state_t;

#endif /* GRADIENT_DESCENT_MOMENTUM_TYPES_H */
