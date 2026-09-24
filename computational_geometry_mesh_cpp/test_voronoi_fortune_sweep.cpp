#include "voronoi_fortune_sweep.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(parabola_directrix(4.0, 0.0) == 2.0);
    std::cout << "test_voronoi_fortune_sweep.cpp passed.\n";
    return 0;
}
