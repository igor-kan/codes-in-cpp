#include "interface.hpp"

namespace codes_persistent_seg_tree {
std::vector<long long> pst_batch_sums_fast(const PersistentSegTree& pst, const std::vector<std::size_t>& vers, std::size_t ql, std::size_t qr) {
    std::vector<long long> out(vers.size(), 0);
    for (std::size_t i = 0; i < vers.size(); ++i) {
        out[i] = pst_query_sum(pst, vers[i], ql, qr);
    }
    return out;
}
} // namespace codes_persistent_seg_tree
