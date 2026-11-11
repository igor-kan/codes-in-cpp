/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for Cooperative Fiber Scheduler with Work-Stealing Queues.
 * Module: actor_fiber_scheduler
 */

#include <assert.h>
#include <math.h>

static inline void actor_fiber_scheduler_verify_contract_day47(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
