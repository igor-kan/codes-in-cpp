#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_monotone_cht_env_d59;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    MonotoneCht ch;
    ch.add_decreasing(3, 4);
    ch.add_decreasing(1, 10);
    assert(ch.query_increasing(2) == 10 && ch.query_increasing(10) == 20);
    return 0;
}
