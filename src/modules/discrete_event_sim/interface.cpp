/**
 * @file interface.cpp
 * @brief Abstract contracts and prototypes for Priority-Queue Discrete Event Simulation Engine.
 * Module: discrete_event_sim
 */

#ifndef DISCRETE_EVENT_SIM_INTERFACE_H
#define DISCRETE_EVENT_SIM_INTERFACE_H

#include "types.cpp"

typedef int (*discrete_event_sim_kernel_fn)(const double* in_data, double* out_data, size_t n);

typedef struct discrete_event_sim_vtable {
    int (*init)(discrete_event_sim_state_t* state, const discrete_event_sim_config_t* cfg);
    int (*execute)(discrete_event_sim_state_t* state, const double* in_vec, double* out_vec, size_t n);
    int (*destroy)(discrete_event_sim_state_t* state);
} discrete_event_sim_vtable_t;

#endif /* DISCRETE_EVENT_SIM_INTERFACE_H */
