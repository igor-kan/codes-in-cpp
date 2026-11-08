/**
 * @file types.cpp
 * @brief Core types and configuration for Discrete Linear Kalman Filter State Estimator.
 * Module: kalman_filter_eigen
 */

#ifndef KALMAN_FILTER_EIGEN_TYPES_H
#define KALMAN_FILTER_EIGEN_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define KALMAN_FILTER_EIGEN_ALIGNMENT 64
#define KALMAN_FILTER_EIGEN_DEFAULT_CAPACITY 1024

typedef struct kalman_filter_eigen_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} kalman_filter_eigen_config_t;

typedef struct kalman_filter_eigen_state {
    void* memory_arena;
    size_t count;
    uint64_t metric_cycles;
    kalman_filter_eigen_config_t config;
} kalman_filter_eigen_state_t;

#endif /* KALMAN_FILTER_EIGEN_TYPES_H */
