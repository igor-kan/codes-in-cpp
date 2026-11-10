/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for 3D Octree Hierarchical Bounding Box Ray Accelerator.
 * Module: octree_ray_caster
 */

#include <assert.h>
#include <math.h>

static inline void octree_ray_caster_verify_contract(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
