/**
 * @file cache_locality.cpp
 * @brief Cache tiling and memory hierarchy optimizations for 3D Spatial Partitioning Octree with Frustum Culling.
 * Module: octree_spatial
 */

#define OCTREE_SPATIAL_CACHE_LINE 64
#define OCTREE_SPATIAL_TILE_DIM 32

void octree_spatial_cache_tiled_step(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += OCTREE_SPATIAL_TILE_DIM) {
        size_t r_end = (r + OCTREE_SPATIAL_TILE_DIM < rows) ? r + OCTREE_SPATIAL_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00005;
            }
        }
    }
}
