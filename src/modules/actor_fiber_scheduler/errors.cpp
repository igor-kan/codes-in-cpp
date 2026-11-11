/**
 * @file errors.cpp
 * @brief Rich diagnostic error reporting for Cooperative Fiber Scheduler with Work-Stealing Queues.
 * Module: actor_fiber_scheduler
 */

typedef enum actor_fiber_scheduler_error_code {
    ACTOR_FIBER_SCHEDULER_STATUS_OK = 0,
    ACTOR_FIBER_SCHEDULER_ERR_NULL_PTR = -20,
    ACTOR_FIBER_SCHEDULER_ERR_OUT_OF_BOUNDS = -21,
    ACTOR_FIBER_SCHEDULER_ERR_DIVERGENCE = -22
} actor_fiber_scheduler_error_code_t;

const char* actor_fiber_scheduler_error_message(actor_fiber_scheduler_error_code_t code) {
    switch (code) {
        case ACTOR_FIBER_SCHEDULER_STATUS_OK: return "Operational success";
        case ACTOR_FIBER_SCHEDULER_ERR_NULL_PTR: return "Null pointer argument";
        case ACTOR_FIBER_SCHEDULER_ERR_OUT_OF_BOUNDS: return "Buffer boundary exceeded";
        case ACTOR_FIBER_SCHEDULER_ERR_DIVERGENCE: return "Numerical divergence detected";
        default: return "Unspecified error code";
    }
}
