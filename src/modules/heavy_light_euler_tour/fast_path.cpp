#include "interface.hpp"

namespace codes_heavy_light_euler_tour {
std::vector<std::int64_t> fast_batch_subtree_sums(const EulerSubtreeEngine& eng, const std::vector<int>& roots) {
    std::vector<std::int64_t> out;
    out.reserve(roots.size());
    for (int r : roots) out.push_back(eng.subtree_sum(r));
    return out;
}
} // namespace codes_heavy_light_euler_tour
