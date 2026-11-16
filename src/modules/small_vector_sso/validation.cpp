#include "interface.hpp"

namespace codes_small_vector_sso {
Status validate_small_vec(const SmallVecInt& v) {
    if (v.ptr == nullptr) return Status::NullOrEmpty;
    if (v.len > v.cap) return Status::InvariantViolation;
    if (v.is_small() && v.cap != SmallVecInt::kInlineCap) return Status::InvariantViolation;
    return Status::Ok;
}
} // namespace codes_small_vector_sso
