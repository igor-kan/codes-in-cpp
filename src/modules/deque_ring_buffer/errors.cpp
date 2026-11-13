/**
 * @file errors.cpp
 * @brief Domain diagnostic error codes and messages for Cacheline-Aligned Circular Deque with Modulo Wrap.
 * Module: deque_ring_buffer
 */

typedef enum deque_ring_buffer_error_status {
    DEQUE_RING_BUFFER_OK = 0,
    DEQUE_RING_BUFFER_ERR_INVALID_PARAM = -10,
    DEQUE_RING_BUFFER_ERR_CAPACITY_LIMIT = -11,
    DEQUE_RING_BUFFER_ERR_NUMERICAL_FAULT = -12
} deque_ring_buffer_error_status_t;

const char* deque_ring_buffer_error_string(deque_ring_buffer_error_status_t err) {
    switch (err) {
        case DEQUE_RING_BUFFER_OK: return "Operational success";
        case DEQUE_RING_BUFFER_ERR_INVALID_PARAM: return "Parameter domain precondition violated";
        case DEQUE_RING_BUFFER_ERR_CAPACITY_LIMIT: return "Buffer capacity boundary reached";
        case DEQUE_RING_BUFFER_ERR_NUMERICAL_FAULT: return "Numerical computation anomaly";
        default: return "Unknown module error code";
    }
}
