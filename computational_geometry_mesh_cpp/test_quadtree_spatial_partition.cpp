#include "quadtree_spatial_partition.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(quad_quadrant(1, 1, 0, 0) == 3);
    std::cout << "test_quadtree_spatial_partition.cpp passed.\n";
    return 0;
}
