#include "interface.hpp"
#include <cassert>

int main() {
    using namespace codes_wavelet_tree_range_kth;
    std::vector<int> a = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    WaveletTree wt(a, 1, 9);
    verify_wavelet_matches_sort(a, wt, 1, 7);
    assert(wt.range_freq(0, 9, 5) == 2);
    assert(wt.range_freq(2, 6, 1) == 1);
    return 0;
}
