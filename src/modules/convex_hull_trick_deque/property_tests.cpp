#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_convex_hull_trick_deque;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    MonotoneCht cht; cht.add_line(5, 0); cht.add_line(1, 8); assert(cht.query(3) == 11);
    return 0;
}
