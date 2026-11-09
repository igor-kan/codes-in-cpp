/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for Priority-Queue Discrete Event Simulation Engine.
 * Module: discrete_event_sim
 */

#include <assert.h>
#include <math.h>

static inline void discrete_event_sim_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
