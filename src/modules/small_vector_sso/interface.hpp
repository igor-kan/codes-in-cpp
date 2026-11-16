#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_small_vector_sso {
Status validate_small_vec(const SmallVecInt& v);
void append_range_fast(SmallVecInt& v, const int64_t* data, std::size_t count);
std::vector<int64_t> batch_reduce_sums(const std::vector<SmallVecInt>& batch);
Status verify_small_vec_invariants(const SmallVecInt& v, const std::vector<int64_t>& oracle);
} // namespace codes_small_vector_sso
