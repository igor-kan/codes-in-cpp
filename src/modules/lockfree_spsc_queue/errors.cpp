/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for Cacheline-Aligned Lock-Free SPSC Queue.
 * Module: lockfree_spsc_queue
 */

typedef enum lockfree_spsc_queue_error {
    LOCKFREE_SPSC_QUEUE_OK = 0,
    LOCKFREE_SPSC_QUEUE_ERR_NULL = -100,
    LOCKFREE_SPSC_QUEUE_ERR_CAPACITY = -101,
    LOCKFREE_SPSC_QUEUE_ERR_CONVERGENCE = -102
} lockfree_spsc_queue_error_t;

const char* lockfree_spsc_queue_strerror(lockfree_spsc_queue_error_t err) {
    switch (err) {
        case LOCKFREE_SPSC_QUEUE_OK: return "Success";
        case LOCKFREE_SPSC_QUEUE_ERR_NULL: return "Encountered null pointer argument";
        case LOCKFREE_SPSC_QUEUE_ERR_CAPACITY: return "Capacity limit exceeded";
        case LOCKFREE_SPSC_QUEUE_ERR_CONVERGENCE: return "Numerical algorithm failed to converge";
        default: return "Unknown error";
    }
}
