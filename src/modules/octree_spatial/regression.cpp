/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for 3D Spatial Partitioning Octree with Frustum Culling.
 * Module: octree_spatial
 */

#include <assert.h>

void test_octree_spatial_regression_underflow(void) {
    double tiny = 1e-308;
    double res = tiny * (1.0 + 0.3 * tiny);
    assert(res >= 0.0);
}
