#include "interface.hpp"

namespace codes_wavelet_tree_range_kth {
std::vector<int> fast_batch_kth(const WaveletTree& wt, const std::vector<std::array<int, 3>>& queries) {
    std::vector<int> out;
    out.reserve(queries.size());
    for (const auto& q : queries) out.push_back(wt.range_kth(q[0], q[1], q[2]));
    return out;
}
} // namespace codes_wavelet_tree_range_kth
