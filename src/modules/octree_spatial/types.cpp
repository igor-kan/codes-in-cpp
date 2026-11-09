/**
 * @file types.cpp
 * @brief Core types and configuration for 3D Spatial Partitioning Octree with Frustum Culling.
 * Module: octree_spatial
 */

#ifndef OCTREE_SPATIAL_TYPES_H
#define OCTREE_SPATIAL_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define OCTREE_SPATIAL_ALIGNMENT 64
#define OCTREE_SPATIAL_CAPACITY 2048

typedef struct octree_spatial_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} octree_spatial_config_t;

typedef struct octree_spatial_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    octree_spatial_config_t config;
} octree_spatial_state_t;

#endif /* OCTREE_SPATIAL_TYPES_H */
