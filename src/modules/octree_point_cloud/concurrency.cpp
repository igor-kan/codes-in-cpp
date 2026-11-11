/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Hierarchical 3D Point Cloud Octree with Radius Search.
 * Module: octree_point_cloud
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct octree_point_cloud_sync_counter {
    volatile uint64_t count;
} octree_point_cloud_sync_counter_t;

static inline void octree_point_cloud_sync_inc_v47(octree_point_cloud_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
