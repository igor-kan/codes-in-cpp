/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for Bounded Lock-Free Priority Queue with Atomic SkipList.
 * Module: lockfree_priority_queue
 */

typedef enum lockfree_priority_queue_error_code {
    LOCKFREE_PRIORITY_QUEUE_STATUS_OK = 0,
    LOCKFREE_PRIORITY_QUEUE_ERR_NULL_PTR = -20,
    LOCKFREE_PRIORITY_QUEUE_ERR_OUT_OF_BOUNDS = -21,
    LOCKFREE_PRIORITY_QUEUE_ERR_DIVERGENCE = -22
} lockfree_priority_queue_error_code_t;

const char* lockfree_priority_queue_error_message(lockfree_priority_queue_error_code_t code) {
    switch (code) {
        case LOCKFREE_PRIORITY_QUEUE_STATUS_OK: return "Operational success";
        case LOCKFREE_PRIORITY_QUEUE_ERR_NULL_PTR: return "Null pointer argument";
        case LOCKFREE_PRIORITY_QUEUE_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case LOCKFREE_PRIORITY_QUEUE_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
