/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for Hierarchical 3D Point Cloud Octree with Radius Search.
 * Module: octree_point_cloud
 */

#ifndef OCTREE_POINT_CLOUD_INTERFACE_H
#define OCTREE_POINT_CLOUD_INTERFACE_H

#include "types.cpp"

typedef int (*octree_point_cloud_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct octree_point_cloud_vtable {
    int (*init)(octree_point_cloud_state_t* state, const octree_point_cloud_config_t* cfg);
    int (*execute)(octree_point_cloud_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(octree_point_cloud_state_t* state);
    int (*destroy)(octree_point_cloud_state_t* state);
} octree_point_cloud_vtable_t;

#endif /* OCTREE_POINT_CLOUD_INTERFACE_H */
