/**
 * @file interface.cpp
 * @brief Abstract contracts and operational prototypes for Cooperative Fiber Scheduler with Work-Stealing Queues.
 * Module: actor_fiber_scheduler
 */

#ifndef ACTOR_FIBER_SCHEDULER_INTERFACE_H
#define ACTOR_FIBER_SCHEDULER_INTERFACE_H

#include "types.cpp"

typedef int (*actor_fiber_scheduler_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct actor_fiber_scheduler_vtable {
    int (*init)(actor_fiber_scheduler_state_t* state, const actor_fiber_scheduler_config_t* cfg);
    int (*execute)(actor_fiber_scheduler_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*reset)(actor_fiber_scheduler_state_t* state);
    int (*destroy)(actor_fiber_scheduler_state_t* state);
} actor_fiber_scheduler_vtable_t;

#endif /* ACTOR_FIBER_SCHEDULER_INTERFACE_H */
