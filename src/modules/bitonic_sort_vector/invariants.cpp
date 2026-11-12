/**
 * @file invariants.cpp
 * @brief Formal mathematical invariant assertions and contracts for Parallel Bitonic Sorting Network for Array Blocks.
 * Module: bitonic_sort_vector
 */

#include <assert.h>
#include <math.h>

static inline void bitonic_sort_vector_check_invariants(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0 || fabs(output) < 1e-12);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
