#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_treap_implicit_rev_d58;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    std::vector<long long> a = {10, 20, 30, 40};
    long long s0 = subarray_sum(a, 0, 3);
    reverse_subarray_twice_check(a, 0, 3);
    assert(subarray_sum(a, 0, 3) == s0);
    return 0;
}
