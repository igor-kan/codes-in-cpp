#include "interface.hpp"

namespace codes_bridges_tarjan_lowlink {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_bridges_tarjan_lowlink
