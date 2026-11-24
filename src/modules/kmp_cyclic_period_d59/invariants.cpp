#include "interface.hpp"

namespace codes_kmp_cyclic_period_d59 {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_kmp_cyclic_period_d59
