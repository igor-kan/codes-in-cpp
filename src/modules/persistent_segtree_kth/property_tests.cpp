#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_persistent_segtree_kth;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    PersistentFreqTree pst(8); int r1 = pst.add(0, 0, 7, 4); assert(pst.kth(0, r1, 0, 7, 1) == 4);
    return 0;
}
