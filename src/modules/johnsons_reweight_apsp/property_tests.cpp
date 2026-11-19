#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_johnsons_reweight_apsp;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    auto d = johnson_apsp(3, {{0,1,10},{0,2,2},{2,1,-1}}); assert(d[0][1] == 1);
    return 0;
}
