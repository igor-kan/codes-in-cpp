#include "interface.hpp"
#include <cstring>

namespace codes_small_vector_sso {
void append_range_fast(SmallVecInt& v, const int64_t* data, std::size_t count) {
    if (!data || count == 0) return;
    v.reserve(v.len + count);
    std::memcpy(v.ptr + v.len, data, count * sizeof(int64_t));
    v.len += count;
}
} // namespace codes_small_vector_sso
