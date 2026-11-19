#include "interface.hpp"

namespace codes_johnsons_reweight_apsp {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_johnsons_reweight_apsp
