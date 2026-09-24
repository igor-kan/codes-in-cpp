#include "line_segment_intersection_bentley.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(ccw_straddle(-1.0, 1.0) == true);
    std::cout << "test_line_segment_intersection_bentley.cpp passed.\n";
    return 0;
}
