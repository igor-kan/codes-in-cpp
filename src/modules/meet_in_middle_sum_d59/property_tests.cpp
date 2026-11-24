#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_meet_in_middle_sum_d59;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    assert(subset_sum_mim({10, 20, 30}, 0));
    return 0;
}
