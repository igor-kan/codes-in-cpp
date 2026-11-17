#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_wavelet_tree_range_kth {
struct WaveletNode {
    int lo = 0;
    int hi = 0;
    int left = -1;
    int right = -1;
    std::vector<int> pref;
};
} // namespace codes_wavelet_tree_range_kth
