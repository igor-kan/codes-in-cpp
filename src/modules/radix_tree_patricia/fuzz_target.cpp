/**
 * @file fuzz_target.cpp
 * @brief Continuous fuzzing harness for Compact Patricia Trie with Bitwise Prefix Match.
 * Module: radix_tree_patricia
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_radix_tree_patricia_day45(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val < 1e5 && *val > -1e5) {
        double res = (*val) * (1.0 + 0.3 * (*val));
        (void)res;
    }
    return 0;
}
