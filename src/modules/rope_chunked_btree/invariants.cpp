#include "interface.hpp"

namespace codes_rope_chunked_btree {
Status verify_rope_invariants(const RopeStore& r, const std::string& expected) {
    std::string flat = rope_flatten(r);
    if (flat != expected) return Status::InvariantViolation;
    for (std::size_t i = 0; i < expected.size(); ++i) {
        if (rope_at(r, i) != expected[i]) return Status::InvariantViolation;
    }
    return Status::Ok;
}
} // namespace codes_rope_chunked_btree
