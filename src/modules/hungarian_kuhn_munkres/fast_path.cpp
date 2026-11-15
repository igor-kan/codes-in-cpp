#include "interface.hpp"

namespace codes_hungarian_kuhn_munkres {
long long evaluate_assignment_cost(std::size_t cols, const std::vector<long long>& mat, const std::vector<std::size_t>& assign) {
    long long s = 0;
    for (std::size_t i = 0; i < assign.size(); ++i) s += mat[i * cols + assign[i]];
    return s;
}
} // namespace codes_hungarian_kuhn_munkres
