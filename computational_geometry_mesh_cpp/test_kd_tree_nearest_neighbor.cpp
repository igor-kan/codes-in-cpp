#include "kd_tree_nearest_neighbor.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(kd_split_axis(5, 3) == 2);
    std::cout << "test_kd_tree_nearest_neighbor.cpp passed.\n";
    return 0;
}
