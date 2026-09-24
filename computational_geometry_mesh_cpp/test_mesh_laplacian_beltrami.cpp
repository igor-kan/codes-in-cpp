#include "mesh_laplacian_beltrami.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(cotangent_weight(1.0, 1.0) == 1.0);
    std::cout << "test_mesh_laplacian_beltrami.cpp passed.\n";
    return 0;
}
