#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_segment_lazy_mul_add_d61 {

LazyMulAddTree::LazyMulAddTree(const std::vector<std::int64_t>& a)
    : n_(static_cast<int>(a.size())) {
    std::size_t cap = static_cast<std::size_t>(4 * n_ + 4);
    sum_.assign(cap, 0);
    add_.assign(cap, 0);
    mul_.assign(cap, 1);
    if (n_ > 0) build(1, 0, n_ - 1, a);
}
void LazyMulAddTree::build(int idx, int l, int r, const std::vector<std::int64_t>& a) {
    if (l == r) {
        sum_[idx] = a[static_cast<std::size_t>(l)];
        return;
    }
    int mid = l + (r - l) / 2;
    build(idx * 2, l, mid, a);
    build(idx * 2 + 1, mid + 1, r, a);
    sum_[idx] = sum_[idx * 2] + sum_[idx * 2 + 1];
}
void LazyMulAddTree::apply(int idx, int len, std::int64_t m, std::int64_t a) {
    sum_[idx] = sum_[idx] * m + a * len;
    mul_[idx] = mul_[idx] * m;
    add_[idx] = add_[idx] * m + a;
}
void LazyMulAddTree::push(int idx, int l, int r) {
    if (mul_[idx] == 1 && add_[idx] == 0) return;
    int mid = l + (r - l) / 2;
    apply(idx * 2, mid - l + 1, mul_[idx], add_[idx]);
    apply(idx * 2 + 1, r - mid, mul_[idx], add_[idx]);
    mul_[idx] = 1;
    add_[idx] = 0;
}
void LazyMulAddTree::pull(int idx) {
    sum_[idx] = sum_[idx * 2] + sum_[idx * 2 + 1];
}
void LazyMulAddTree::update(int idx, int l, int r, int ql, int qr, std::int64_t m, std::int64_t a) {
    if (ql <= l && r <= qr) {
        apply(idx, r - l + 1, m, a);
        return;
    }
    push(idx, l, r);
    int mid = l + (r - l) / 2;
    if (ql <= mid) update(idx * 2, l, mid, ql, qr, m, a);
    if (qr > mid) update(idx * 2 + 1, mid + 1, r, ql, qr, m, a);
    pull(idx);
}
std::int64_t LazyMulAddTree::query(int idx, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) return sum_[idx];
    push(idx, l, r);
    int mid = l + (r - l) / 2;
    std::int64_t res = 0;
    if (ql <= mid) res += query(idx * 2, l, mid, ql, qr);
    if (qr > mid) res += query(idx * 2 + 1, mid + 1, r, ql, qr);
    return res;
}
void LazyMulAddTree::range_add(int l, int r, std::int64_t v) {
    if (n_ > 0) update(1, 0, n_ - 1, l, r, 1, v);
}
void LazyMulAddTree::range_mul(int l, int r, std::int64_t v) {
    if (n_ > 0) update(1, 0, n_ - 1, l, r, v, 0);
}
std::int64_t LazyMulAddTree::range_sum(int l, int r) {
    return n_ > 0 ? query(1, 0, n_ - 1, l, r) : 0;
}

} // namespace codes_segment_lazy_mul_add_d61
