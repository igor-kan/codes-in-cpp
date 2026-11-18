#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_li_chao_segment_lines {

LiChaoTree::LiChaoTree(int max_x) : n_(max_x), tree_(4 * max_x + 4) {}

void LiChaoTree::add_line(std::int64_t m, std::int64_t b) {
    insert_rec(1, 0, n_ - 1, AffineLine{m, b});
}

void LiChaoTree::insert_rec(int v, int l, int r, AffineLine nw) {
    int mid = (l + r) >> 1;
    bool left_better = nw.eval(l) < tree_[v].eval(l);
    bool mid_better  = nw.eval(mid) < tree_[v].eval(mid);
    if (mid_better) std::swap(tree_[v], nw);
    if (l == r) return;
    if (left_better != mid_better) insert_rec(v << 1, l, mid, nw);
    else insert_rec(v << 1 | 1, mid + 1, r, nw);
}

std::int64_t LiChaoTree::query(int x) const {
    return query_rec(1, 0, n_ - 1, x);
}

std::int64_t LiChaoTree::query_rec(int v, int l, int r, int x) const {
    std::int64_t res = tree_[v].eval(x);
    if (l == r) return res;
    int mid = (l + r) >> 1;
    if (x <= mid) return std::min(res, query_rec(v << 1, l, mid, x));
    return std::min(res, query_rec(v << 1 | 1, mid + 1, r, x));
}

} // namespace codes_li_chao_segment_lines
