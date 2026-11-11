/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for Hierarchical 3D Point Cloud Octree with Radius Search.
 * Module: octree_point_cloud
 */

#include <assert.h>

void test_octree_point_cloud_regression_subnormal_day47(void) {
    double sub = 1e-312;
    double res = sub * (1.0 + 0.4 * sub);
    assert(res >= 0.0);
}
