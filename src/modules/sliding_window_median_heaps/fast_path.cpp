#include "interface.hpp"
#include <algorithm>

namespace codes_sliding_window_median_heaps {
double fast_median_sort_slice(std::vector<std::int64_t> slice) {
    std::sort(slice.begin(), slice.end());
    std::size_t m = slice.size();
    if (m % 2 == 1) return static_cast<double>(slice[m / 2]);
    return (static_cast<double>(slice[m / 2 - 1]) + static_cast<double>(slice[m / 2])) * 0.5;
}
} // namespace codes_sliding_window_median_heaps
