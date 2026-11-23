#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_treap_implicit_rev_d58 {

void reverse_subarray_twice_check(std::vector<long long>& xs, int l, int r) {
    if (l < 0 || r >= static_cast<int>(xs.size()) || l > r) throw std::out_of_range("bad range");
    std::reverse(xs.begin() + l, xs.begin() + r + 1);
}

long long subarray_sum(const std::vector<long long>& xs, int l, int r) {
    long long s = 0;
    for (int i = l; i <= r; ++i) s += xs[i];
    return s;
}

} // namespace codes_treap_implicit_rev_d58
