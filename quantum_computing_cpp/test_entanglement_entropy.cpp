#include "entanglement_entropy.hpp"
#include <cassert>
#include <iostream>

int main() {
    double s_bell = von_neumann_entropy_bipartite(0.5, 0.5);
    assert(std::abs(s_bell - 1.0) < 1e-7);
    std::cout << "test_entanglement_entropy passed.\n";
    return 0;
}
