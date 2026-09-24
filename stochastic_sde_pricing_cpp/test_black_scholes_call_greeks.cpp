#include "black_scholes_call_greeks.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(bs_delta_call(0.65) == 0.65);
    std::cout << "test_black_scholes_call_greeks.cpp passed.\n";
    return 0;
}
