#include "point_in_polygon_ray_casting.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(ray_intersects_edge(0.0, 0.5, 0.0, 1.0) == true);
    std::cout << "test_point_in_polygon_ray_casting.cpp passed.\n";
    return 0;
}
