#include "gram_schmidt_modified.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(proj_scalar(4.0, 2.0) == 2.0);
    std::cout << "test_gram_schmidt_modified.cpp passed.\n";
    return 0;
}
