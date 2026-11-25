#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_segment_lazy_add_d60 {

LazySegTree::LazySegTree(int n) : n_(n), sum_(4 * n + 4, 0), lazy_(4 * n + 4, 0) {}
void LazySegTree::push(int idx, int l, int r) {
    if (lazy_[idx] != 0 && l < r) {
        int mid = l + (r - l) / 2;
        std::int64_t d = lazy_[idx];
        sum_[idx * 2] += d * (mid - l + 1);
        lazy_[idx * 2] += d;
        sum_[idx * 2 + 1] += d * (r - mid);
        lazy_[idx * 2 + 1] += d;
        lazy_[idx] = 0;
    }
}
void LazySegTree::add_rec(int idx, int l, int r, int ql, int qr, std::int64_t v) {
    if (ql <= l && r <= qr) {
        sum_[idx] += v * (r - l + 1);
        lazy_[idx] += v;
        return;
    }
    push(idx, l, r);
    int mid = l + (r - l) / 2;
    if (ql <= mid) add_rec(idx * 2, l, mid, ql, qr, v);
    if (qr > mid) add_rec(idx * 2 + 1, mid + 1, r, ql, qr, v);
    sum_[idx] = sum_[idx * 2] + sum_[idx * 2 + 1];
}
std::int64_t LazySegTree::sum_rec(int idx, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return sum_[idx];
    push(idx, l, r);
    int mid = l + (r - l) / 2;
    std::int64_t res = 0;
    if (ql <= mid) res += sum_rec(idx * 2, l, mid, ql, qr);
    if (qr > mid) res += sum_rec(idx * 2 + 1, mid + 1, r, ql, qr);
    return res;
}
void LazySegTree::range_add(int l, int r, std::int64_t v) { add_rec(1, 0, n_ - 1, l, r, v); }
std::int64_t LazySegTree::range_sum(int l, int r) { return sum_rec(1, 0, n_ - 1, l, r); }

} // namespace codes_segment_lazy_add_d60
