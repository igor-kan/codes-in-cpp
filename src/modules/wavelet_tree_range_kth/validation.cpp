#include "interface.hpp"

namespace codes_wavelet_tree_range_kth {
void validate_range_kth(int n, int l, int r, int k) {
    if (l < 0 || r > n || l >= r || k < 0 || k >= (r - l)) {
        throw std::out_of_range("invalid range_kth bounds");
    }
}
} // namespace codes_wavelet_tree_range_kth
