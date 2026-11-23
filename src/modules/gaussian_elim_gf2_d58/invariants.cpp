#include "interface.hpp"

namespace codes_gaussian_elim_gf2_d58 {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_gaussian_elim_gf2_d58
