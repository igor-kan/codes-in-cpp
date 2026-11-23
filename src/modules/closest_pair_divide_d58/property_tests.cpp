#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_closest_pair_divide_d58;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    assert(closest_pair_dist2({{0,0},{0,0},{5,5}}) == 0);
    return 0;
}
