#include "interface.hpp"

namespace codes_fenwick_range_add_cpp {

DualFenwick::DualFenwick(int n) : n_(n), b1_(static_cast<std::size_t>(n + 2), 0), b2_(static_cast<std::size_t>(n + 2), 0) {
    if (n <= 0) throw std::invalid_argument("size must be positive");
}

void DualFenwick::add_bit(std::vector<std::int64_t>& bit, int pos, std::int64_t val) {
    for (; pos <= n_; pos += pos & -pos) bit[static_cast<std::size_t>(pos)] += val;
}

std::int64_t DualFenwick::query_bit(const std::vector<std::int64_t>& bit, int pos) const {
    std::int64_t s = 0;
    for (; pos > 0; pos -= pos & -pos) s += bit[static_cast<std::size_t>(pos)];
    return s;
}

void DualFenwick::range_add(int l, int r, std::int64_t delta) {
    validate_interval(n_, l, r);
    int l1 = l + 1, r1 = r + 1;
    add_bit(b1_, l1, delta);
    add_bit(b1_, r1 + 1, -delta);
    add_bit(b2_, l1, delta * (l1 - 1));
    add_bit(b2_, r1 + 1, -delta * r1);
}

std::int64_t DualFenwick::prefix_sum(int idx) const {
    if (idx < 0) return 0;
    if (idx >= n_) idx = n_ - 1;
    int p = idx + 1;
    return query_bit(b1_, p) * p - query_bit(b2_, p);
}

std::int64_t DualFenwick::range_sum(int l, int r) const {
    validate_interval(n_, l, r);
    return prefix_sum(r) - (l > 0 ? prefix_sum(l - 1) : 0);
}

} // namespace codes_fenwick_range_add_cpp
