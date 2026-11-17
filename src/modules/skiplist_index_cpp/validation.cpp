#include "interface.hpp"

namespace codes_skiplist_index_cpp {
void validate_range_bounds(std::int64_t lo, std::int64_t hi) {
    if (lo > hi) throw std::invalid_argument("range lower bound exceeds upper bound");
}
} // namespace codes_skiplist_index_cpp
