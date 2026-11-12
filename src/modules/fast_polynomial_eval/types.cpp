/**
 * @file types.cpp
 * @brief Domain types, memory layouts, and configurations for Horner Rule and Estrin Scheme Polynomial Evaluation.
 * Module: fast_polynomial_eval | Algorithm Family: polynomial
 */

#ifndef FAST_POLYNOMIAL_EVAL_TYPES_H
#define FAST_POLYNOMIAL_EVAL_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define FAST_POLYNOMIAL_EVAL_ALIGNMENT 64
#define FAST_POLYNOMIAL_EVAL_BASE_CAPACITY 1024

typedef struct fast_polynomial_eval_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} fast_polynomial_eval_config_t;

typedef struct fast_polynomial_eval_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    fast_polynomial_eval_config_t config;
} fast_polynomial_eval_state_t;

#endif /* FAST_POLYNOMIAL_EVAL_TYPES_H */
