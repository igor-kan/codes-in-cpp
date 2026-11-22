#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_cartesian_min_tree_d57 {

std::pair<int, std::vector<CartNode>> build_cartesian_min_tree(const std::vector<long long>& xs) {
    if (xs.empty()) throw std::invalid_argument("non-empty array required");
    int n = static_cast<int>(xs.size());
    std::vector<CartNode> nodes(n);
    std::vector<int> stk;
    for (int i = 0; i < n; ++i) {
        nodes[i].val = xs[i];
        int last = -1;
        while (!stk.empty() && nodes[stk.back()].val > xs[i]) {
            last = stk.back();
            stk.pop_back();
        }
        nodes[i].left = last;
        if (!stk.empty()) nodes[stk.back()].right = i;
        stk.push_back(i);
    }
    return {stk.front(), nodes};
}

} // namespace codes_cartesian_min_tree_d57
