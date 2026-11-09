/**
 * @file interface.cpp
 * @brief Abstract contracts and prototypes for Bounded Multi-Producer Multi-Consumer Queue.
 * Module: lockfree_mpmc_queue
 */

#ifndef LOCKFREE_MPMC_QUEUE_INTERFACE_H
#define LOCKFREE_MPMC_QUEUE_INTERFACE_H

#include "types.cpp"

typedef int (*lockfree_mpmc_queue_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct lockfree_mpmc_queue_vtable {
    int (*init)(lockfree_mpmc_queue_state_t* state, const lockfree_mpmc_queue_config_t* cfg);
    int (*execute)(lockfree_mpmc_queue_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(lockfree_mpmc_queue_state_t* state);
} lockfree_mpmc_queue_vtable_t;

#endif /* LOCKFREE_MPMC_QUEUE_INTERFACE_H */
