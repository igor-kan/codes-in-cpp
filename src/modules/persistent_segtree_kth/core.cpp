#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_persistent_segtree_kth {

PersistentFreqTree::PersistentFreqTree(int dom) : dom_(dom), nodes_(1) {}
int PersistentFreqTree::add(int prev_root, int l, int r, int pos) {
    int cur = static_cast<int>(nodes_.size());
    nodes_.push_back(nodes_[prev_root]);
    ++nodes_[cur].cnt;
    if (l < r) {
        int mid = (l + r) >> 1;
        if (pos <= mid) nodes_[cur].l = add(nodes_[prev_root].l, l, mid, pos);
        else nodes_[cur].r = add(nodes_[prev_root].r, mid + 1, r, pos);
    }
    return cur;
}
int PersistentFreqTree::kth(int root_l, int root_r, int l, int r, int k) const {
    if (l == r) return l;
    int left_cnt = nodes_[nodes_[root_r].l].cnt - nodes_[nodes_[root_l].l].cnt;
    int mid = (l + r) >> 1;
    if (k <= left_cnt) return kth(nodes_[root_l].l, nodes_[root_r].l, l, mid, k);
    return kth(nodes_[root_l].r, nodes_[root_r].r, mid + 1, r, k - left_cnt);
}

} // namespace codes_persistent_segtree_kth
