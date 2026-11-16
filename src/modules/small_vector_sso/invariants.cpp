#include "interface.hpp"

namespace codes_small_vector_sso {
Status verify_small_vec_invariants(const SmallVecInt& v, const std::vector<int64_t>& oracle) {
    if (validate_small_vec(v) != Status::Ok) return Status::InvariantViolation;
    if (v.len != oracle.size()) return Status::InvariantViolation;
    for (std::size_t i = 0; i < v.len; ++i) {
        if (v.ptr[i] != oracle[i]) return Status::InvariantViolation;
    }
    return Status::Ok;
}
} // namespace codes_small_vector_sso
