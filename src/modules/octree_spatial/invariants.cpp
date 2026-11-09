/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for 3D Spatial Partitioning Octree with Frustum Culling.
 * Module: octree_spatial
 */

#include <assert.h>
#include <math.h>

static inline void octree_spatial_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
