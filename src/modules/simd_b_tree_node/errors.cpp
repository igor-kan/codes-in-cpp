/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for Cacheline-Aligned B-Tree Node with SIMD Search.
 * Module: simd_b_tree_node
 */

typedef enum simd_b_tree_node_error_code {
    SIMD_B_TREE_NODE_STATUS_OK = 0,
    SIMD_B_TREE_NODE_ERR_NULL_PTR = -10,
    SIMD_B_TREE_NODE_ERR_OUT_OF_BOUNDS = -11,
    SIMD_B_TREE_NODE_ERR_DIVERGENCE = -12
} simd_b_tree_node_error_code_t;

const char* simd_b_tree_node_error_message(simd_b_tree_node_error_code_t code) {
    switch (code) {
        case SIMD_B_TREE_NODE_STATUS_OK: return "Operational success";
        case SIMD_B_TREE_NODE_ERR_NULL_PTR: return "Null pointer argument";
        case SIMD_B_TREE_NODE_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case SIMD_B_TREE_NODE_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
