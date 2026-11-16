#include "interface.hpp"

namespace codes_bimap_bidirectional_index {
Status verify_bimap_invariants(const IntStrBiMap& bm) {
    if (bm.fwd_slots.size() != bm.rev_pairs.size() || bm.fwd_slots.size() != bm.count) return Status::InvariantViolation;
    for (const auto& s : bm.fwd_slots) {
        int64_t back = -1;
        if (!find_by_val(bm, s.val, back) || back != s.key) return Status::InvariantViolation;
    }
    return Status::Ok;
}
} // namespace codes_bimap_bidirectional_index
