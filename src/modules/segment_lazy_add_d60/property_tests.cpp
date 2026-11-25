#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_segment_lazy_add_d60;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    LazySegTree seg(16);
    std::vector<std::int64_t> ref(16, 0);
    for (int k = 0; k < 12; ++k) {
        int l = k % 8, r = l + (k % 7);
        std::int64_t v = (k & 1) ? 4 : -2;
        seg.range_add(l, r, v);
        for (int i = l; i <= r; ++i) ref[i] += v;
    }
    std::int64_t exp = 0;
    for (int i = 2; i <= 11; ++i) exp += ref[i];
    assert(seg.range_sum(2, 11) == exp);
    return 0;
}
