#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_scc_condensation_d59;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    auto res = tarjan_scc_condense(3, {{0,1},{1,2}});
    assert(res.comp_count == 3);
    return 0;
}
