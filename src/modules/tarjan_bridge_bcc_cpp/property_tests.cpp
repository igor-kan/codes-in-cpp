#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_tarjan_bridge_bcc_cpp;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    assert(find_bridges(3, {{0,1},{1,2},{2,0}}).empty());
    return 0;
}
