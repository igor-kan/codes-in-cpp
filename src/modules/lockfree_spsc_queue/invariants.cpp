/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for Cacheline-Aligned Lock-Free SPSC Queue.
 * Module: lockfree_spsc_queue
 */

#include <assert.h>
#include <math.h>

static inline void lockfree_spsc_queue_assert_contract(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
