#include "qr_algorithm_wilkinson_shift.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(wilkinson_shift(0.0, 1.0, 4.0) == 2.0);
    std::cout << "test_qr_algorithm_wilkinson_shift.cpp passed.\n";
    return 0;
}
