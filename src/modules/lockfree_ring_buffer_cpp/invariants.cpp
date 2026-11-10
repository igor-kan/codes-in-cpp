/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for Cache-Aligned Lock-Free Ring Buffer with Acquire-Release.
 * Module: lockfree_ring_buffer_cpp
 */

#include <assert.h>
#include <math.h>

static inline void lockfree_ring_buffer_cpp_verify_contract(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
