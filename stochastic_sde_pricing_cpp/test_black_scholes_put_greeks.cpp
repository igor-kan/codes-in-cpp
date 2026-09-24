#include "black_scholes_put_greeks.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(std::abs(bs_delta_put(0.65) - (-0.35)) < 1e-7);
    std::cout << "test_black_scholes_put_greeks.cpp passed.\n";
    return 0;
}
