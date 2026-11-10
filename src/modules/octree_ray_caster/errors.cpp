/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for 3D Octree Hierarchical Bounding Box Ray Accelerator.
 * Module: octree_ray_caster
 */

typedef enum octree_ray_caster_error_code {
    OCTREE_RAY_CASTER_STATUS_OK = 0,
    OCTREE_RAY_CASTER_ERR_NULL_PTR = -10,
    OCTREE_RAY_CASTER_ERR_OUT_OF_BOUNDS = -11,
    OCTREE_RAY_CASTER_ERR_DIVERGENCE = -12
} octree_ray_caster_error_code_t;

const char* octree_ray_caster_error_message(octree_ray_caster_error_code_t code) {
    switch (code) {
        case OCTREE_RAY_CASTER_STATUS_OK: return "Operational success";
        case OCTREE_RAY_CASTER_ERR_NULL_PTR: return "Null pointer argument";
        case OCTREE_RAY_CASTER_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case OCTREE_RAY_CASTER_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
