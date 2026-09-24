#include "antithetic_variates_sampler.hpp"
#include <cassert>
#include <iostream>

int main() {
    auto [z1, z2] = antithetic_pair(1.5); assert(std::abs(z1 + z2) < 1e-7);
    std::cout << "test_antithetic_variates_sampler.cpp passed.\n";
    return 0;
}
