/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for 2D Spatial Collision Quadtree with Range Pruning.
 * Module: quadtree_collision
 */

#include <assert.h>
#include <math.h>

static inline void quadtree_collision_assert_contract(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
