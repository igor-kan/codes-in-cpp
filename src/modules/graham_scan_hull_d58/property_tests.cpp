#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_graham_scan_hull_d58;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    assert(convex_hull_area2({{0,0},{1,1},{2,2}}) == 0);
    return 0;
}
