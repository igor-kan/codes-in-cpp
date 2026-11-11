/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for Hierarchical 3D Point Cloud Octree with Radius Search.
 * Module: octree_point_cloud
 */

#include <assert.h>
#include <math.h>

static inline void octree_point_cloud_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
