#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_spfa_tarjan_neg_cycle;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    auto cyc = find_negative_cycle(3, {{0,1,5},{1,2,5},{0,2,12}});
    assert(cyc.empty());
    return 0;
}
