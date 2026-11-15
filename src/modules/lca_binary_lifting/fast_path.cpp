#include "interface.hpp"

namespace codes_lca_binary_lifting {
std::size_t kth_ancestor(const LcaIndex& idx, std::size_t u, std::size_t k) {
    for (std::size_t bit = 0; bit < idx.log_n && k > 0; ++bit) {
        if (k & (1ULL << bit)) {
            u = idx.up[bit * idx.n + u];
        }
    }
    return u;
}
} // namespace codes_lca_binary_lifting
