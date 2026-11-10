/**
 * @file boundary.cpp
 * @brief Boundary validation and exceptional input guarding for 3D Octree Hierarchical Bounding Box Ray Accelerator.
 * Module: octree_ray_caster
 */

#include "types.cpp"
#include <math.h>
#include <stdbool.h>

static inline bool octree_ray_caster_is_valid_float(double x) {
    return isfinite(x);
}

static inline double octree_ray_caster_clamp_input(double x, double min_val, double max_val) {
    if (!isfinite(x)) return 0.0;
    if (x < min_val) return min_val;
    if (x > max_val) return max_val;
    return x;
}
