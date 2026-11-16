#include "interface.hpp"

namespace codes_rope_chunked_btree {
Status validate_rope_range(const RopeStore& r, std::size_t start, std::size_t len) {
    if (r.root < 0) return len == 0 ? Status::Ok : Status::NullOrEmpty;
    std::size_t total = r.pool[static_cast<std::size_t>(r.root)].total_len;
    if (start > total || len > total - start) return Status::OutOfBounds;
    return Status::Ok;
}
} // namespace codes_rope_chunked_btree
