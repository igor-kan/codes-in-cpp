#include "interface.hpp"

namespace codes_fenwick_range_add_cpp {
void validate_interval(int n, int l, int r) {
    if (l < 0 || r >= n || l > r) throw std::out_of_range("interval out of bounds");
}
} // namespace codes_fenwick_range_add_cpp
