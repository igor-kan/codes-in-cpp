#include "interface.hpp"

namespace codes_sliding_window_median_heaps {
void validate_window(std::size_t n, std::size_t k) {
    if (k == 0 || k > n) throw std::invalid_argument("window width k must satisfy 1 <= k <= N");
}
} // namespace codes_sliding_window_median_heaps
