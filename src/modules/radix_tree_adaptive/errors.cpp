/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for Adaptive Radix Tree (ART) with Path Compression.
 * Module: radix_tree_adaptive
 */

typedef enum radix_tree_adaptive_error_code {
    RADIX_TREE_ADAPTIVE_STATUS_OK = 0,
    RADIX_TREE_ADAPTIVE_ERR_NULL_PTR = -20,
    RADIX_TREE_ADAPTIVE_ERR_OUT_OF_BOUNDS = -21,
    RADIX_TREE_ADAPTIVE_ERR_DIVERGENCE = -22
} radix_tree_adaptive_error_code_t;

const char* radix_tree_adaptive_error_message(radix_tree_adaptive_error_code_t code) {
    switch (code) {
        case RADIX_TREE_ADAPTIVE_STATUS_OK: return "Operational success";
        case RADIX_TREE_ADAPTIVE_ERR_NULL_PTR: return "Null pointer argument";
        case RADIX_TREE_ADAPTIVE_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case RADIX_TREE_ADAPTIVE_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
