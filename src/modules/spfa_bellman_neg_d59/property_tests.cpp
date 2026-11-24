#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_spfa_bellman_neg_d59;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    std::vector<std::vector<SpfaEdge>> cyc(2);
    cyc[0] = {{1, 1}}; cyc[1] = {{0, -2}};
    assert(spfa_distances(2, 0, cyc).first);
    return 0;
}
