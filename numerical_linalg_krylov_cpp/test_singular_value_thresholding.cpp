#include "singular_value_thresholding.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(soft_threshold(5.0, 2.0) == 3.0); assert(soft_threshold(1.0, 2.0) == 0.0);
    std::cout << "test_singular_value_thresholding.cpp passed.\n";
    return 0;
}
