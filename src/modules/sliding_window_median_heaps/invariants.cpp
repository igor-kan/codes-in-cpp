#include "interface.hpp"
#include <cmath>

namespace codes_sliding_window_median_heaps {
void verify_medians_oracle(const std::vector<std::int64_t>& nums, std::size_t k, const std::vector<double>& got) {
    if (got.size() != nums.size() - k + 1) throw std::logic_error("median count mismatch");
    for (std::size_t i = 0; i < got.size(); ++i) {
        std::vector<std::int64_t> slice(nums.begin() + static_cast<std::ptrdiff_t>(i),
                                        nums.begin() + static_cast<std::ptrdiff_t>(i + k));
        double expected = fast_median_sort_slice(std::move(slice));
        if (std::abs(got[i] - expected) > 1e-9) throw std::logic_error("median disagreed with sort oracle");
    }
}
} // namespace codes_sliding_window_median_heaps
