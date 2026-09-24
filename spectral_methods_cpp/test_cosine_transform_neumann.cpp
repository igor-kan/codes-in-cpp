#include "cosine_transform_neumann.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(dct_mode(1, 0.0) == 1.0);
    std::cout << "test_cosine_transform_neumann.cpp passed.\n";
    return 0;
}
