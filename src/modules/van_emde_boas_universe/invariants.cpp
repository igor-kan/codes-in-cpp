#include "interface.hpp"

namespace codes_van_emde_boas_universe {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_van_emde_boas_universe
