/**
 * @file concurrency.cpp
 * @brief Thread-safe reentrancy and atomic state primitives for Spherical Linear Interpolation (SLERP) for Quaternions.
 * Module: quaternion_slerp_cpp
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct quaternion_slerp_cpp_sync_state {
    volatile uint64_t counter;
    volatile uint32_t concurrency_count;
} quaternion_slerp_cpp_sync_state_t;

static inline void quaternion_slerp_cpp_sync_increment(quaternion_slerp_cpp_sync_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELEASE);
}
