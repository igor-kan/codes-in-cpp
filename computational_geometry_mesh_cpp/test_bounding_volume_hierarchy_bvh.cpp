#include "bounding_volume_hierarchy_bvh.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(aabb_overlap(0, 2, 1, 3) == true);
    std::cout << "test_bounding_volume_hierarchy_bvh.cpp passed.\n";
    return 0;
}
