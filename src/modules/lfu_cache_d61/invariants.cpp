#include "interface.hpp"

namespace codes_lfu_cache_d61 {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_lfu_cache_d61
