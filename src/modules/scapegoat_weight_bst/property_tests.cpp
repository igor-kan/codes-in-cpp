#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_scapegoat_weight_bst;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    ScapegoatTree sg;
    for (int i = 1; i <= 15; ++i) sg.insert(i);
    assert(sg.kth(7) == 8);
    return 0;
}
