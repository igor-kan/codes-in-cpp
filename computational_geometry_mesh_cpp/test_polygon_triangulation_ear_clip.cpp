#include "polygon_triangulation_ear_clip.hpp"
#include <cassert>
#include <iostream>

int main() {
    assert(is_ear_candidate(true, true) == true);
    std::cout << "test_polygon_triangulation_ear_clip.cpp passed.\n";
    return 0;
}
