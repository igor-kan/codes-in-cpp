#include "interface.hpp"
#include <algorithm>

namespace codes_wavelet_tree_range_kth {

WaveletTree::WaveletTree(const std::vector<int>& data, int min_val, int max_val) : n_(static_cast<int>(data.size())) {
    if (data.empty() || min_val > max_val) throw std::invalid_argument("invalid wavelet bounds");
    std::vector<int> copy = data;
    build(copy.begin(), copy.end(), min_val, max_val);
}

int WaveletTree::build(std::vector<int>::iterator b, std::vector<int>::iterator e, int lo, int hi) {
    int id = static_cast<int>(nodes_.size());
    nodes_.push_back({lo, hi, -1, -1, {}});
    if (lo == hi || b == e) return id;
    int mid = lo + (hi - lo) / 2;
    auto pred = [mid](int x) { return x <= mid; };
    nodes_[static_cast<std::size_t>(id)].pref.reserve(static_cast<std::size_t>(e - b) + 1);
    nodes_[static_cast<std::size_t>(id)].pref.push_back(0);
    for (auto it = b; it != e; ++it) {
        int prev = nodes_[static_cast<std::size_t>(id)].pref.back();
        nodes_[static_cast<std::size_t>(id)].pref.push_back(prev + (pred(*it) ? 1 : 0));
    }
    auto pivot = std::stable_partition(b, e, pred);
    int lid = build(b, pivot, lo, mid);
    int rid = build(pivot, e, mid + 1, hi);
    nodes_[static_cast<std::size_t>(id)].left = lid;
    nodes_[static_cast<std::size_t>(id)].right = rid;
    return id;
}

int WaveletTree::kth_rec(int u, int l, int r, int k) const {
    const auto& nd = nodes_[static_cast<std::size_t>(u)];
    if (nd.lo == nd.hi) return nd.lo;
    int in_left = nd.pref[static_cast<std::size_t>(r)] - nd.pref[static_cast<std::size_t>(l)];
    int lb = nd.pref[static_cast<std::size_t>(l)];
    int rb = nd.pref[static_cast<std::size_t>(r)];
    if (k < in_left) return kth_rec(nd.left, lb, rb, k);
    return kth_rec(nd.right, l - lb, r - rb, k - in_left);
}

int WaveletTree::freq_rec(int u, int l, int r, int x) const {
    if (l >= r) return 0;
    const auto& nd = nodes_[static_cast<std::size_t>(u)];
    if (x < nd.lo || x > nd.hi) return 0;
    if (nd.lo == nd.hi) return r - l;
    int mid = nd.lo + (nd.hi - nd.lo) / 2;
    int lb = nd.pref[static_cast<std::size_t>(l)];
    int rb = nd.pref[static_cast<std::size_t>(r)];
    if (x <= mid) return freq_rec(nd.left, lb, rb, x);
    return freq_rec(nd.right, l - lb, r - rb, x);
}

int WaveletTree::range_kth(int l, int r, int k) const {
    validate_range_kth(n_, l, r, k);
    return kth_rec(0, l, r, k);
}

int WaveletTree::range_freq(int l, int r, int x) const {
    if (l < 0 || r > n_ || l > r) throw std::out_of_range("invalid frequency range");
    return freq_rec(0, l, r, x);
}

} // namespace codes_wavelet_tree_range_kth
