/**
 * @file types.cpp
 * @brief Core types and configuration for Hierarchical 3D Point Cloud Octree with Radius Search.
 * Module: octree_point_cloud
 */

#ifndef OCTREE_POINT_CLOUD_TYPES_H
#define OCTREE_POINT_CLOUD_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define OCTREE_POINT_CLOUD_ALIGNMENT 64
#define OCTREE_POINT_CLOUD_DEFAULT_SZ 8192

typedef struct octree_point_cloud_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} octree_point_cloud_config_t;

typedef struct octree_point_cloud_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    octree_point_cloud_config_t config;
} octree_point_cloud_state_t;

#endif /* OCTREE_POINT_CLOUD_TYPES_H */
