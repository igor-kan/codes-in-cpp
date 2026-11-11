/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for Bounded Lock-Free Priority Queue with Atomic SkipList.
 * Module: lockfree_priority_queue
 */

#ifndef LOCKFREE_PRIORITY_QUEUE_INTERFACE_H
#define LOCKFREE_PRIORITY_QUEUE_INTERFACE_H

#include "types.cpp"

typedef int (*lockfree_priority_queue_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct lockfree_priority_queue_vtable {
    int (*init)(lockfree_priority_queue_state_t* state, const lockfree_priority_queue_config_t* cfg);
    int (*execute)(lockfree_priority_queue_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(lockfree_priority_queue_state_t* state);
    int (*destroy)(lockfree_priority_queue_state_t* state);
} lockfree_priority_queue_vtable_t;

#endif /* LOCKFREE_PRIORITY_QUEUE_INTERFACE_H */
