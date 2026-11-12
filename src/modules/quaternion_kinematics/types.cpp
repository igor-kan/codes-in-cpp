/**
 * @file types.cpp
 * @brief Domain types, memory layouts, and configurations for Hamilton Quaternion 3D Rotation and Normalization.
 * Module: quaternion_kinematics | Algorithm Family: quaternion
 */

#ifndef QUATERNION_KINEMATICS_TYPES_H
#define QUATERNION_KINEMATICS_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define QUATERNION_KINEMATICS_ALIGNMENT 64
#define QUATERNION_KINEMATICS_BASE_CAPACITY 1024

typedef struct quaternion_kinematics_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
    uint64_t seed;
} quaternion_kinematics_config_t;

typedef struct quaternion_kinematics_state {
    void* buffer;
    size_t count;
    uint64_t operations;
    double accumulator;
    quaternion_kinematics_config_t config;
} quaternion_kinematics_state_t;

#endif /* QUATERNION_KINEMATICS_TYPES_H */
