/**
 * @file types.cpp
 * @brief Core types and configuration for Consteval Compile-Time Matrix Exponential via Pade.
 * Module: compile_time_matrix_exp
 */

#ifndef COMPILE_TIME_MATRIX_EXP_TYPES_H
#define COMPILE_TIME_MATRIX_EXP_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define COMPILE_TIME_MATRIX_EXP_ALIGNMENT 64
#define COMPILE_TIME_MATRIX_EXP_DEFAULT_SZ 8192

typedef struct compile_time_matrix_exp_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} compile_time_matrix_exp_config_t;

typedef struct compile_time_matrix_exp_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    compile_time_matrix_exp_config_t config;
} compile_time_matrix_exp_state_t;

#endif /* COMPILE_TIME_MATRIX_EXP_TYPES_H */
