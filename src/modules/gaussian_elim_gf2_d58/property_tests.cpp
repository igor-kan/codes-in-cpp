#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_gaussian_elim_gf2_d58;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    std::vector<uint64_t> xs = {10, 20, 30, 7};
    uint64_t mx = gf2_max_subset_xor(xs);
    for (uint64_t v : xs) assert(mx >= v);
    return 0;
}
