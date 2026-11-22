#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_seg_tree_max_sub_d57;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    std::vector<long long> arr = {5, -9, 6, 4, -2, 3};
    MaxSubSegTree st(arr);
    assert(st.query_best(0, 5) == 11 && st.query_best(2, 5) == 11);
    return 0;
}
