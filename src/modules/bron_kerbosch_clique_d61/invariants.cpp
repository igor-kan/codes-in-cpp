#include "interface.hpp"

namespace codes_bron_kerbosch_clique_d61 {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_bron_kerbosch_clique_d61
