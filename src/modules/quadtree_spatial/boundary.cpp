/**
 * Boundary condition checking and IEEE-754 edge-case handlers for 2D Spatial Indexing Quadtree with Range Search.
 * Module: quadtree_spatial
 */

#ifndef BOUNDARY_QUADTREE_SPATIAL_H
#define BOUNDARY_QUADTREE_SPATIAL_H

#include <math.h>
#include <stdbool.h>

static inline bool quadtree_spatial_is_finite_input(double x) {
    return isfinite(x);
}

static inline double quadtree_spatial_clamp(double val, double min_val, double max_val) {
    const double t = val < min_val ? min_val : val;
    return t > max_val ? max_val : t;
}

#endif /* BOUNDARY_QUADTREE_SPATIAL_H */
