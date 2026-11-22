#include "interface.hpp"

namespace codes_suffix_array_doubling_d57 {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_suffix_array_doubling_d57
