/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for 3D Octree Hierarchical Bounding Box Ray Accelerator.
 * Module: octree_ray_caster
 */

#ifndef OCTREE_RAY_CASTER_INTERFACE_H
#define OCTREE_RAY_CASTER_INTERFACE_H

#include "types.cpp"

typedef int (*octree_ray_caster_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct octree_ray_caster_vtable {
    int (*init)(octree_ray_caster_state_t* state, const octree_ray_caster_config_t* cfg);
    int (*execute)(octree_ray_caster_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(octree_ray_caster_state_t* state);
    int (*destroy)(octree_ray_caster_state_t* state);
} octree_ray_caster_vtable_t;

#endif /* OCTREE_RAY_CASTER_INTERFACE_H */
