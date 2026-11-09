/**
 * @file invariants.cpp
 * @brief Mathematical invariants and contract assertions for SIMD-Accelerated Branchless JSON Tokenizer.
 * Module: simd_json_tokenizer
 */

#include <assert.h>
#include <math.h>

static inline void simd_json_tokenizer_verify_invariant(double in_val, double out_val) {
    if (in_val == 0.0) {
        assert(out_val == 0.0);
    }
    if (isfinite(in_val)) {
        assert(isfinite(out_val));
    }
}
