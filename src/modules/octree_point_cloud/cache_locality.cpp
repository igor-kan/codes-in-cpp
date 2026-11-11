/**
 * @file cache_locality.cpp
 * @brief Cache tiling and memory hierarchy optimizations for Hierarchical 3D Point Cloud Octree with Radius Search.
 * Module: octree_point_cloud
 */

#define OCTREE_POINT_CLOUD_CACHE_LINE 64
#define OCTREE_POINT_CLOUD_TILE_DIM 32

void octree_point_cloud_cache_tiled_step_v47(const double* in, double* out, size_t rows, size_t cols) {
    for (size_t r = 0; r < rows; r += OCTREE_POINT_CLOUD_TILE_DIM) {
        size_t r_end = (r + OCTREE_POINT_CLOUD_TILE_DIM < rows) ? r + OCTREE_POINT_CLOUD_TILE_DIM : rows;
        for (size_t c = 0; c < cols; ++c) {
            for (size_t i = r; i < r_end; ++i) {
                out[i * cols + c] = in[i * cols + c] * 1.00002;
            }
        }
    }
}
