/**
 * @file types.cpp
 * @brief Domain types, memory layouts, and configurations for Spherical Linear Interpolation (SLERP) for Quaternions.
 * Module: quaternion_slerp_cpp | Algorithm Family: quaternion
 */

#ifndef QUATERNION_SLERP_CPP_TYPES_H
#define QUATERNION_SLERP_CPP_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define QUATERNION_SLERP_CPP_ALIGNMENT 64
#define QUATERNION_SLERP_CPP_CAPACITY 4096

typedef struct quaternion_slerp_cpp_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} quaternion_slerp_cpp_config_t;

typedef struct quaternion_slerp_cpp_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    double accumulator;
    quaternion_slerp_cpp_config_t config;
} quaternion_slerp_cpp_state_t;

#endif /* QUATERNION_SLERP_CPP_TYPES_H */
