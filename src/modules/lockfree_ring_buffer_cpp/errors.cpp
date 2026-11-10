/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for Cache-Aligned Lock-Free Ring Buffer with Acquire-Release.
 * Module: lockfree_ring_buffer_cpp
 */

typedef enum lockfree_ring_buffer_cpp_error_code {
    LOCKFREE_RING_BUFFER_CPP_STATUS_OK = 0,
    LOCKFREE_RING_BUFFER_CPP_ERR_NULL_PTR = -10,
    LOCKFREE_RING_BUFFER_CPP_ERR_OUT_OF_BOUNDS = -11,
    LOCKFREE_RING_BUFFER_CPP_ERR_DIVERGENCE = -12
} lockfree_ring_buffer_cpp_error_code_t;

const char* lockfree_ring_buffer_cpp_error_message(lockfree_ring_buffer_cpp_error_code_t code) {
    switch (code) {
        case LOCKFREE_RING_BUFFER_CPP_STATUS_OK: return "Operational success";
        case LOCKFREE_RING_BUFFER_CPP_ERR_NULL_PTR: return "Null pointer argument";
        case LOCKFREE_RING_BUFFER_CPP_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case LOCKFREE_RING_BUFFER_CPP_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
