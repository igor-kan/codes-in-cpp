#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_seg_tree_max_sub_d57 {

MaxSubNode MaxSubSegTree::combine(const MaxSubNode& l, const MaxSubNode& r) {
    return {
        l.sum + r.sum,
        std::max(l.pref, l.sum + r.pref),
        std::max(r.suff, r.sum + l.suff),
        std::max({l.best, r.best, l.suff + r.pref})
    };
}

MaxSubSegTree::MaxSubSegTree(const std::vector<long long>& xs) : n_(static_cast<int>(xs.size())), t_(4 * xs.size() + 4) {
    if (xs.empty()) throw std::invalid_argument("non-empty input");
    for (int i = 0; i < n_; ++i) set_rec(1, 0, n_ - 1, i, xs[i]);
}

void MaxSubSegTree::set_rec(int node, int l, int r, int pos, long long v) {
    if (l == r) {
        t_[node] = {v, v, v, v};
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) set_rec(node * 2, l, mid, pos, v);
    else set_rec(node * 2 + 1, mid + 1, r, pos, v);
    t_[node] = combine(t_[node * 2], t_[node * 2 + 1]);
}

void MaxSubSegTree::update(int pos, long long val) {
    if (pos < 0 || pos >= n_) throw std::out_of_range("index out of range");
    set_rec(1, 0, n_ - 1, pos, val);
}

MaxSubNode MaxSubSegTree::query_rec(int node, int l, int r, int ql, int qr) const {
    if (ql <= l && r <= qr) return t_[node];
    int mid = (l + r) / 2;
    if (qr <= mid) return query_rec(node * 2, l, mid, ql, qr);
    if (ql > mid) return query_rec(node * 2 + 1, mid + 1, r, ql, qr);
    return combine(query_rec(node * 2, l, mid, ql, qr), query_rec(node * 2 + 1, mid + 1, r, ql, qr));
}

long long MaxSubSegTree::query_best(int ql, int qr) const {
    return query_rec(1, 0, n_ - 1, ql, qr).best;
}

} // namespace codes_seg_tree_max_sub_d57
