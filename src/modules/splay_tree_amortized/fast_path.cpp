#include "interface.hpp"

namespace codes_splay_tree_amortized {
static int build_balanced(SplayTree& t, const std::vector<long long>& keys, std::size_t l, std::size_t r, int par) {
    if (l >= r) return -1;
    std::size_t mid = l + (r - l) / 2;
    int id = static_cast<int>(t.pool.size());
    SplayNode node;
    node.key = keys[mid];
    node.parent = par;
    t.pool.push_back(node);
    int lc = build_balanced(t, keys, l, mid, id);
    int rc = build_balanced(t, keys, mid + 1, r, id);
    t.pool[static_cast<std::size_t>(id)].ch[0] = lc;
    t.pool[static_cast<std::size_t>(id)].ch[1] = rc;
    splay_pull(t, id);
    return id;
}

void splay_insert_sorted_batch(SplayTree& tree, const std::vector<long long>& sorted_keys) {
    tree.pool.clear();
    tree.pool.reserve(sorted_keys.size());
    tree.root = build_balanced(tree, sorted_keys, 0, sorted_keys.size(), -1);
}
} // namespace codes_splay_tree_amortized
