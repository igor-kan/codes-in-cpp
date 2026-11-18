#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_fractional_cascading_grid {

FractionalCascader::FractionalCascader(const std::vector<std::vector<std::int64_t>>& catalogs) : raw_(catalogs) {}

std::vector<std::int64_t> FractionalCascader::query_lower_bounds(std::int64_t x) const {
    std::vector<std::int64_t> out(raw_.size(), -1);
    for (std::size_t i = 0; i < raw_.size(); ++i) {
        auto it = std::lower_bound(raw_[i].begin(), raw_[i].end(), x);
        if (it != raw_[i].end()) out[i] = *it;
    }
    return out;
}

} // namespace codes_fractional_cascading_grid
