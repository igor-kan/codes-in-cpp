/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for Cacheline-Aligned Lock-Free SPSC Queue.
 * Module: lockfree_spsc_queue
 */

#ifndef LOCKFREE_SPSC_QUEUE_INTERFACE_H
#define LOCKFREE_SPSC_QUEUE_INTERFACE_H

#include "types.cpp"

typedef int (*lockfree_spsc_queue_transform_fn)(const double* in_data, double* out_data, size_t n);

typedef struct lockfree_spsc_queue_interface {
    int (*init)(lockfree_spsc_queue_state_t* state, const lockfree_spsc_queue_config_t* cfg);
    int (*execute)(lockfree_spsc_queue_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(lockfree_spsc_queue_state_t* state);
    int (*destroy)(lockfree_spsc_queue_state_t* state);
} lockfree_spsc_queue_interface_t;

#endif /* LOCKFREE_SPSC_QUEUE_INTERFACE_H */
