#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_wavelet_tree_range_kth {
class WaveletTree {
public:
    WaveletTree(const std::vector<int>& data, int min_val, int max_val);
    int range_kth(int l, int r, int k) const;
    int range_freq(int l, int r, int x) const;
    int size() const { return n_; }

private:
    int n_;
    std::vector<WaveletNode> nodes_;
    int build(std::vector<int>::iterator b, std::vector<int>::iterator e, int lo, int hi);
    int kth_rec(int u, int l, int r, int k) const;
    int freq_rec(int u, int l, int r, int x) const;
};

void validate_range_kth(int n, int l, int r, int k);
std::vector<int> fast_batch_kth(const WaveletTree& wt, const std::vector<std::array<int, 3>>& queries);
std::vector<int> parallel_range_kth(const std::vector<int>& data, int lo, int hi, const std::vector<std::array<int, 3>>& queries);
void verify_wavelet_matches_sort(const std::vector<int>& data, const WaveletTree& wt, int l, int r);
} // namespace codes_wavelet_tree_range_kth
