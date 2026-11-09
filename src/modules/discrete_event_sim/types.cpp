/**
 * @file types.cpp
 * @brief Core types and configuration for Priority-Queue Discrete Event Simulation Engine.
 * Module: discrete_event_sim
 */

#ifndef DISCRETE_EVENT_SIM_TYPES_H
#define DISCRETE_EVENT_SIM_TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define DISCRETE_EVENT_SIM_ALIGNMENT 64
#define DISCRETE_EVENT_SIM_CAPACITY 2048

typedef struct discrete_event_sim_config {
    size_t capacity;
    double tolerance;
    uint32_t flags;
} discrete_event_sim_config_t;

typedef struct discrete_event_sim_state {
    void* buffer;
    size_t count;
    uint64_t cycles;
    discrete_event_sim_config_t config;
} discrete_event_sim_state_t;

#endif /* DISCRETE_EVENT_SIM_TYPES_H */
