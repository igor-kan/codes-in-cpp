#include "arnoldi_subspace_projection.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(krylov_dim(5) == 5);
    std::cout << "test_arnoldi_subspace_projection.cpp passed.\n";
    return 0;
}
