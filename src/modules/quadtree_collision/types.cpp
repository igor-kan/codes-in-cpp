/**
 * @file types.cpp
 * @brief Core types and configuration for 2D Spatial Collision Quadtree with Range Pruning.
 * Module: quadtree_collision
 */

#ifndef QUADTREE_COLLISION_TYPES_H
#define QUADTREE_COLLISION_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define QUADTREE_COLLISION_ALIGNMENT 64
#define QUADTREE_COLLISION_DEFAULT_CAPACITY 1024

typedef struct quadtree_collision_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} quadtree_collision_config_t;

typedef struct quadtree_collision_state {
    void* memory_arena;
    size_t count;
    uint64_t metric_cycles;
    quadtree_collision_config_t config;
} quadtree_collision_state_t;

#endif /* QUADTREE_COLLISION_TYPES_H */
