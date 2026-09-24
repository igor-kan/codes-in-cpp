#include "gmres_minimal_residual.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(gmres_residual(0.1, 10.0) == 1.0);
    std::cout << "test_gmres_minimal_residual.cpp passed.\n";
    return 0;
}
