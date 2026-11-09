/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for 3D Spatial Partitioning Octree with Frustum Culling.
 * Module: octree_spatial
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct octree_spatial_sync_counter {
    volatile uint64_t count;
} octree_spatial_sync_counter_t;

static inline void octree_spatial_sync_inc(octree_spatial_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
