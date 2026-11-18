#include "interface.hpp"

namespace codes_spfa_tarjan_neg_cycle {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_spfa_tarjan_neg_cycle
