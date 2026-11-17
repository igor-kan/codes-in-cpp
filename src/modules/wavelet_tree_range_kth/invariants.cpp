#include "interface.hpp"
#include <algorithm>

namespace codes_wavelet_tree_range_kth {
void verify_wavelet_matches_sort(const std::vector<int>& data, const WaveletTree& wt, int l, int r) {
    std::vector<int> sub(data.begin() + l, data.begin() + r);
    std::sort(sub.begin(), sub.end());
    for (int k = 0; k < r - l; ++k) {
        if (wt.range_kth(l, r, k) != sub[static_cast<std::size_t>(k)]) {
            throw std::logic_error("wavelet range_kth disagreed with sorted slice");
        }
    }
}
} // namespace codes_wavelet_tree_range_kth
