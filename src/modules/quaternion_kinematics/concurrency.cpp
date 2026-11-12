/**
 * @file concurrency.cpp
 * @brief Thread-safe reentrancy and atomic state primitives for Hamilton Quaternion 3D Rotation and Normalization.
 * Module: quaternion_kinematics
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct quaternion_kinematics_atomic_state {
    volatile uint64_t counter;
    volatile uint32_t active_threads;
} quaternion_kinematics_atomic_state_t;

static inline void quaternion_kinematics_atomic_increment(quaternion_kinematics_atomic_state_t* s) {
    __atomic_fetch_add(&s->counter, 1, __ATOMIC_RELAXED);
}
