/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for 2D Spatial Collision Quadtree with Range Pruning.
 * Module: quadtree_collision
 */

#ifndef QUADTREE_COLLISION_INTERFACE_H
#define QUADTREE_COLLISION_INTERFACE_H

#include "types.cpp"

typedef int (*quadtree_collision_transform_fn)(const double* in_data, double* out_data, size_t n);

typedef struct quadtree_collision_interface {
    int (*init)(quadtree_collision_state_t* state, const quadtree_collision_config_t* cfg);
    int (*execute)(quadtree_collision_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(quadtree_collision_state_t* state);
    int (*destroy)(quadtree_collision_state_t* state);
} quadtree_collision_interface_t;

#endif /* QUADTREE_COLLISION_INTERFACE_H */
