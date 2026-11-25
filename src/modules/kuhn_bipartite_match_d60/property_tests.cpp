#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_kuhn_bipartite_match_d60;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    std::vector<BipartiteEdge> bottleneck = {{0,0},{1,0},{2,0}};
    assert(kuhn_max_matching(3, 3, bottleneck) == 1);
    return 0;
}
