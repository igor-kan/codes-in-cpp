/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for 3D Octree Hierarchical Bounding Box Ray Accelerator.
 * Module: octree_ray_caster
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct octree_ray_caster_sync_counter {
    volatile uint64_t count;
} octree_ray_caster_sync_counter_t;

static inline void octree_ray_caster_sync_inc(octree_ray_caster_sync_counter_t* c) {
    __atomic_fetch_add(&c->count, 1, __ATOMIC_RELAXED);
}
