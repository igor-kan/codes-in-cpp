#include "interface.hpp"

namespace codes_euler_tour_forest_dyn {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_euler_tour_forest_dyn
