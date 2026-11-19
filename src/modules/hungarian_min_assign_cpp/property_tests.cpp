#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_hungarian_min_assign_cpp;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    assert(hungarian_min_cost({{10, 1}, {2, 10}}).total_cost == 3);
    return 0;
}
