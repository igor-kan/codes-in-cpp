#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_li_chao_convex_line_tree {

LiChaoTree::LiChaoTree(int max_x) : max_x_(max_x), tree_(4 * (max_x + 1)) {
    if (max_x <= 0) throw std::invalid_argument("max_x must be positive");
}

void LiChaoTree::insert(int node, int l, int r, LinearFn fn) {
    int mid = l + (r - l) / 2;
    bool left_better = fn.eval(l) < tree_[node].eval(l);
    bool mid_better = fn.eval(mid) < tree_[node].eval(mid);
    if (mid_better) std::swap(tree_[node], fn);
    if (l == r) return;
    if (left_better != mid_better) insert(node * 2, l, mid, fn);
    else insert(node * 2 + 1, mid + 1, r, fn);
}

void LiChaoTree::add_line(long long m, long long b) {
    insert(1, 0, max_x_, LinearFn{m, b});
}

long long LiChaoTree::query_rec(int node, int l, int r, int x) const {
    long long cur = tree_[node].eval(x);
    if (l == r) return cur;
    int mid = l + (r - l) / 2;
    if (x <= mid) return std::min(cur, query_rec(node * 2, l, mid, x));
    return std::min(cur, query_rec(node * 2 + 1, mid + 1, r, x));
}

long long LiChaoTree::query(int x) const {
    if (x < 0 || x > max_x_) throw std::out_of_range("x out of range");
    return query_rec(1, 0, max_x_, x);
}

} // namespace codes_li_chao_convex_line_tree
