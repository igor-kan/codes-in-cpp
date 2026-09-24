#include "delaunay_bowyer_watson.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(in_circumcircle(3.0, 4.0) == true);
    std::cout << "test_delaunay_bowyer_watson.cpp passed.\n";
    return 0;
}
