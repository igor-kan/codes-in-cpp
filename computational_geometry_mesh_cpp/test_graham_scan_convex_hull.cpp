#include "graham_scan_convex_hull.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(cross_product_2d(0, 0, 1, 0, 0, 1) > 0);
    std::cout << "test_graham_scan_convex_hull.cpp passed.\n";
    return 0;
}
