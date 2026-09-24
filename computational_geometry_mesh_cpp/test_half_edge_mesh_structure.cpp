#include "half_edge_mesh_structure.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(twin_id(0) == 1); assert(twin_id(1) == 0);
    std::cout << "test_half_edge_mesh_structure.cpp passed.\n";
    return 0;
}
