/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for Hierarchical 3D Point Cloud Octree with Radius Search.
 * Module: octree_point_cloud
 */

typedef enum octree_point_cloud_error_code {
    OCTREE_POINT_CLOUD_STATUS_OK = 0,
    OCTREE_POINT_CLOUD_ERR_NULL_PTR = -20,
    OCTREE_POINT_CLOUD_ERR_OUT_OF_BOUNDS = -21,
    OCTREE_POINT_CLOUD_ERR_DIVERGENCE = -22
} octree_point_cloud_error_code_t;

const char* octree_point_cloud_error_message(octree_point_cloud_error_code_t code) {
    switch (code) {
        case OCTREE_POINT_CLOUD_STATUS_OK: return "Operational success";
        case OCTREE_POINT_CLOUD_ERR_NULL_PTR: return "Null pointer argument";
        case OCTREE_POINT_CLOUD_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case OCTREE_POINT_CLOUD_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
