#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_tarjan_lca_offline_d58;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    auto res = tarjan_offline_lca(4, 0, {{0,1},{1,2},{1,3}}, {{2,3},{3,2}});
    assert(res[0] == res[1] && res[0] == 1);
    return 0;
}
