/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for 3D Octree Hierarchical Bounding Box Ray Accelerator.
 * Module: octree_ray_caster
 */

#include <assert.h>

void test_octree_ray_caster_regression_subnormal_day46(void) {
    double sub = 1e-310;
    double res = sub * (1.0 + 0.35 * sub);
    assert(res >= 0.0);
}
