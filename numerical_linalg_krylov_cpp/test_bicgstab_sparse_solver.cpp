#include "bicgstab_sparse_solver.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(bicgstab_omega(3.0, 6.0) == 0.5);
    std::cout << "test_bicgstab_sparse_solver.cpp passed.\n";
    return 0;
}
