#include "interface.hpp"
#include <cassert>
#include <cmath>

int main() {
    using namespace codes_cartesian_min_tree_d57;
    auto chks = parallel_checksum_batches({{1, 2, 3}, {4, 5, 6}});
    assert(chks.size() == 2 && chks[0] != chks[1]);
    std::vector<long long> xs = {5, 1, 4, 2, 3};
    auto [root, tree] = build_cartesian_min_tree(xs);
    for (int i = 0; i < 5; ++i) {
        if (tree[i].left != -1) assert(tree[i].val <= tree[tree[i].left].val);
        if (tree[i].right != -1) assert(tree[i].val <= tree[tree[i].right].val);
    }
    assert(tree[root].val == 1);
    return 0;
}
