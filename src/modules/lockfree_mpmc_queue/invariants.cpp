/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for Bounded Multi-Producer Multi-Consumer Queue.
 * Module: lockfree_mpmc_queue
 */

#include <assert.h>
#include <math.h>

static inline void lockfree_mpmc_queue_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
