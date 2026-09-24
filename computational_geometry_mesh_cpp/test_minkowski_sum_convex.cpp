#include "minkowski_sum_convex.hpp"
#include <cassert>
#include <iostream>

int main() {
    auto [x, y] = minkowski_add(1, 2, 3, 4); assert(x == 4 && y == 6);
    std::cout << "test_minkowski_sum_convex.cpp passed.\n";
    return 0;
}
