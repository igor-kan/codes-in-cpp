#include "interface.hpp"

namespace codes_eulerian_hierholzer_circuit {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_eulerian_hierholzer_circuit
