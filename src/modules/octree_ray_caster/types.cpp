/**
 * @file types.cpp
 * @brief Core types and configuration for 3D Octree Hierarchical Bounding Box Ray Accelerator.
 * Module: octree_ray_caster
 */

#ifndef OCTREE_RAY_CASTER_TYPES_H
#define OCTREE_RAY_CASTER_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define OCTREE_RAY_CASTER_ALIGNMENT 64
#define OCTREE_RAY_CASTER_CAPACITY 4096

typedef struct octree_ray_caster_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} octree_ray_caster_config_t;

typedef struct octree_ray_caster_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    octree_ray_caster_config_t config;
} octree_ray_caster_state_t;

#endif /* OCTREE_RAY_CASTER_TYPES_H */
