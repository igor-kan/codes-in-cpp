#include "interface.hpp"

namespace codes_segment_lazy_mul_add_d61 {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_segment_lazy_mul_add_d61
