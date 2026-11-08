/**
 * @file concurrency.cpp
 * @brief Thread safety and reentrancy model for Discrete Linear Kalman Filter State Estimator.
 * Module: kalman_filter_eigen
 */

#include <stdint.h>
#include <stdbool.h>

typedef struct kalman_filter_eigen_atomic_counter {
    volatile uint64_t value;
} kalman_filter_eigen_atomic_counter_t;

static inline void kalman_filter_eigen_counter_inc(kalman_filter_eigen_atomic_counter_t* c) {
    __atomic_fetch_add(&c->value, 1, __ATOMIC_RELAXED);
}
