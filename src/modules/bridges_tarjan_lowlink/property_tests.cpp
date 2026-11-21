#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_bridges_tarjan_lowlink;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    auto br_cyc = find_undirected_bridges(4, {{0, 1}, {1, 2}, {2, 3}, {3, 0}});
    assert(br_cyc.empty());
    return 0;
}
