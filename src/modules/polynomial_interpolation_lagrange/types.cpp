/**
 * @file types.cpp
 * @brief Domain types, memory layouts, and configurations for Barycentric Lagrange Polynomial Interpolator.
 * Module: polynomial_interpolation_lagrange | Algorithm Family: interpolation
 */

#ifndef POLYNOMIAL_INTERPOLATION_LAGRANGE_TYPES_H
#define POLYNOMIAL_INTERPOLATION_LAGRANGE_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define POLYNOMIAL_INTERPOLATION_LAGRANGE_ALIGNMENT 64
#define POLYNOMIAL_INTERPOLATION_LAGRANGE_CAPACITY 2048

typedef struct polynomial_interpolation_lagrange_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} polynomial_interpolation_lagrange_config_t;

typedef struct polynomial_interpolation_lagrange_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    polynomial_interpolation_lagrange_config_t config;
} polynomial_interpolation_lagrange_state_t;

#endif /* POLYNOMIAL_INTERPOLATION_LAGRANGE_TYPES_H */
