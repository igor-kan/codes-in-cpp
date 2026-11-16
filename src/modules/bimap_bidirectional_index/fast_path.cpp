#include "interface.hpp"

namespace codes_bimap_bidirectional_index {
std::size_t bulk_insert_pairs(IntStrBiMap& bm, const std::vector<std::pair<int64_t, std::string>>& items) {
    std::size_t added = 0;
    for (const auto& [k, v] : items) {
        if (insert_pair(bm, k, v) == Status::Ok) ++added;
    }
    return added;
}
} // namespace codes_bimap_bidirectional_index
