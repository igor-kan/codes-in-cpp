#include "marching_cubes_isolevel.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(cube_sign_index(5, 0) == 1); assert(cube_sign_index(5, 1) == 0);
    std::cout << "test_marching_cubes_isolevel.cpp passed.\n";
    return 0;
}
