#include "quantum_walk_hadamard.hpp"
#include <cassert>
#include <iostream>

int main() {
    auto coin = hadamard_coin_step(1.0, 0.0);
    assert(std::abs(coin.first - coin.second) < 1e-7);
    std::cout << "test_quantum_walk_hadamard passed.\n";
    return 0;
}
