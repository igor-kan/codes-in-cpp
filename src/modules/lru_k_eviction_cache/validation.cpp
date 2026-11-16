#include "interface.hpp"

namespace codes_lru_k_eviction_cache {
Status validate_capacity(std::size_t capacity) {
    if (capacity == 0) return Status::InvalidInput;
    return Status::Ok;
}
} // namespace codes_lru_k_eviction_cache
