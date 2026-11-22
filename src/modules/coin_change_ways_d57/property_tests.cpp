#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_coin_change_ways_d57;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    assert(count_coin_combinations({1, 2, 5}, 10) == count_coin_combinations({5, 1, 2}, 10));
    return 0;
}
