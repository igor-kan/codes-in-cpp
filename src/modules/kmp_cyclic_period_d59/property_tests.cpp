#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_kmp_cyclic_period_d59;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    assert(shortest_exact_period("aaaaaa") == 1);
    return 0;
}
