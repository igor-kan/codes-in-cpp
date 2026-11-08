/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for 2D Spatial Collision Quadtree with Range Pruning.
 * Module: quadtree_collision
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct quadtree_collision_atomic_counter {
    volatile uint64_t value;
} quadtree_collision_atomic_counter_t;

static inline void quadtree_collision_counter_inc(quadtree_collision_atomic_counter_t* c) {
    __atomic_fetch_add(&c->value, 1, __ATOMIC_RELAXED);
}
