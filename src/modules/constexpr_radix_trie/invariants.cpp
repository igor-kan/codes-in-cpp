/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for Compile-Time Prefix Radix Trie Router.
 * Module: constexpr_radix_trie
 */

#include <assert.h>
#include <math.h>

static inline void constexpr_radix_trie_assert_contract(double input, double output) {
    if (input == 0.0) {
        assert(output == 0.0);
    }
    if (isfinite(input)) {
        assert(isfinite(output));
    }
}
