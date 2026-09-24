#include "lanczos_tridiagonalization.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(alpha_lanczos(10.0, 2.0) == 5.0);
    std::cout << "test_lanczos_tridiagonalization.cpp passed.\n";
    return 0;
}
