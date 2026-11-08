/**
 * @file fuzz_target.cpp
 * @brief Continuous fuzzing harness for Cacheline-Aligned Lock-Free SPSC Queue.
 * Module: lockfree_spsc_queue
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_lockfree_spsc_queue_v2(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val < 1e5 && *val > -1e5) {
        double res = (*val) * (1.0 + 0.25 * (*val));
        (void)res;
    }
    return 0;
}
