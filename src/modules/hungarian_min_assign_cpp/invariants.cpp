#include "interface.hpp"

namespace codes_hungarian_min_assign_cpp {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_hungarian_min_assign_cpp
