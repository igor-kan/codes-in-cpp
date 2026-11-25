#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_convex_hull_monotone_d60;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    auto h = convex_hull_ccw({{0,0},{1,1},{1,0},{0,1},{3,0},{0,3}});
    assert(h.size() == 3 && polygon_area2x(h) == 9);
    return 0;
}
