#include "chebyshev_extrema_nodes.hpp"
#include <cassert>
#include <iostream>

int main() {
    auto x = cheb_nodes(4); assert(x.size() == 5); assert(std::abs(x[0] - 1.0) < 1e-7);
    std::cout << "test_chebyshev_extrema_nodes.cpp passed.\n";
    return 0;
}
