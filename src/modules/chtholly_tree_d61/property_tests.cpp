#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_chtholly_tree_d61;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    ChthollyTree ct(16);
    std::vector<std::int64_t> ref(16, 0);
    for (int k = 0; k < 30; ++k) {
        int l = k % 16;
        int r = l + (k % 5);
        std::int64_t v = static_cast<std::int64_t>(k % 7) - 3;
        ct.assign(l, r, v);
        for (int i = l; i <= r; ++i) ref[static_cast<std::size_t>(i)] = v;
    }
    for (int l = 0; l < 16; l += 3) {
        std::int64_t exact = 0;
        for (int i = l; i < 16; ++i) {
            exact += ref[static_cast<std::size_t>(i)];
            assert(ct.range_sum(l, i) == exact);
        }
    }
    return 0;
}
