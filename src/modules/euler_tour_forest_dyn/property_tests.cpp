#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_euler_tour_forest_dyn;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    EulerSubtreeIndex et(4, 0, {{0,1},{1,2},{2,3}}, {1, 2, 3, 4});
    assert(et.query_subtree_sum(2) == 7);
    return 0;
}
