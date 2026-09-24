#include "cholesky_banachiewicz.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(cholesky_diag(25.0, 9.0) == 4.0);
    std::cout << "test_cholesky_banachiewicz.cpp passed.\n";
    return 0;
}
