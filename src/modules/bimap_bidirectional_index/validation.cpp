#include "interface.hpp"

namespace codes_bimap_bidirectional_index {
Status validate_pair_inputs(int64_t key, const std::string& val) {
    if (val.empty()) return Status::NullOrEmpty;
    if (key < 0 && val.size() > 4096) return Status::OutOfBounds;
    return Status::Ok;
}
} // namespace codes_bimap_bidirectional_index
