#include "givens_rotation_matrix.hpp"
#include <cassert>
#include <iostream>

int main() {
    auto [c, s] = givens_c_s(3.0, 4.0); assert(std::abs(c*c + s*s - 1.0) < 1e-7);
    std::cout << "test_givens_rotation_matrix.cpp passed.\n";
    return 0;
}
