#include "sine_transform_dirichlet.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(dst_mode(1, 0.0) == 0.0);
    std::cout << "test_sine_transform_dirichlet.cpp passed.\n";
    return 0;
}
