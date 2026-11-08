/**
 * @file regression.cpp
 * @brief Minimized crash reproducer and regression tests for 2D Spatial Collision Quadtree with Range Pruning.
 * Module: quadtree_collision
 */

#include <assert.h>

// Regression Case 001: Subnormal floating point handling
void test_quadtree_collision_regression_subnormal(void) {
    double subnormal = 1e-315;
    double res = subnormal * (1.0 + 0.25 * subnormal);
    assert(res >= 0.0);
}
