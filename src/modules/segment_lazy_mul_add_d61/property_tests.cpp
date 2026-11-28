#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_segment_lazy_mul_add_d61;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    std::vector<std::int64_t> a(12);
    for (int i = 0; i < 12; ++i) a[static_cast<std::size_t>(i)] = i + 1;
    LazyMulAddTree seg(a);
    std::vector<std::int64_t> ref = a;
    for (int k = 0; k < 20; ++k) {
        int l = k % 12;
        int r = l + (k % 4);
        if (k % 2 == 0) {
            seg.range_mul(l, r, 2);
            for (int i = l; i <= r; ++i) ref[static_cast<std::size_t>(i)] *= 2;
        } else {
            seg.range_add(l, r, 3);
            for (int i = l; i <= r; ++i) ref[static_cast<std::size_t>(i)] += 3;
        }
    }
    for (int l = 0; l < 12; l += 2) {
        std::int64_t exact = 0;
        for (int i = l; i < 12; ++i) {
            exact += ref[static_cast<std::size_t>(i)];
            assert(seg.range_sum(l, i) == exact);
        }
    }
    return 0;
}
