#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_kruskal_dsu_mst_weight;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    auto [w, cnt] = kruskal_mst(3, {{0, 1, 7}, {1, 2, 3}, {0, 2, 9}});
    assert(cnt == 2 && w == 10);
    return 0;
}
