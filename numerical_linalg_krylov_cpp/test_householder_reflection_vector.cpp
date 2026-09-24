#include "householder_reflection_vector.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(reflect_norm(3.0, 5.0) == 8.0);
    std::cout << "test_householder_reflection_vector.cpp passed.\n";
    return 0;
}
