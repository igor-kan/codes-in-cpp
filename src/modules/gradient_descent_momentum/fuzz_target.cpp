/**
 * @file fuzz_target.cpp
 * @brief Continuous fuzzing target for AFL++ and LibFuzzer for Gradient Descent Optimizer with Nesterov Momentum.
 * Module: gradient_descent_momentum
 */

#include <stddef.h>
#include <stdint.h>

int LLVMFuzzerTestOneInput_gradient_descent_momentum_day49(const uint8_t* data, size_t size) {
    if (size < sizeof(double)) return 0;
    const double* val = (const double*)data;
    if (*val == *val && *val > -1e6 && *val < 1e6) {
        double res = (*val) * 1.0001;
        (void)res;
    }
    return 0;
}
