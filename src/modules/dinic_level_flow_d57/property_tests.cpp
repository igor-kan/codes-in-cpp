#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_dinic_level_flow_d57;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    DinicSolver dn(3);
    dn.add_edge(0, 1, 7); dn.add_edge(1, 2, 5);
    assert(dn.max_flow(0, 2) == 5);
    return 0;
}
