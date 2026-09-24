#include "euler_maruyama_gbm.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(std::abs(gbm_drift(0.05, 0.1) - 0.005) < 1e-7);
    std::cout << "test_euler_maruyama_gbm.cpp passed.\n";
    return 0;
}
