/**
 * @file interface.cpp
 * @brief Abstract contracts and prototypes for 3D Spatial Partitioning Octree with Frustum Culling.
 * Module: octree_spatial
 */

#ifndef OCTREE_SPATIAL_INTERFACE_H
#define OCTREE_SPATIAL_INTERFACE_H

#include "types.cpp"

typedef int (*octree_spatial_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct octree_spatial_vtable {
    int (*init)(octree_spatial_state_t* state, const octree_spatial_config_t* cfg);
    int (*execute)(octree_spatial_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(octree_spatial_state_t* state);
} octree_spatial_vtable_t;

#endif /* OCTREE_SPATIAL_INTERFACE_H */
