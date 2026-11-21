#include "interface.hpp"

namespace codes_kruskal_dsu_mst_weight {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_kruskal_dsu_mst_weight
