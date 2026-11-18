#include "interface.hpp"

namespace codes_golden_section_convex_opt {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_golden_section_convex_opt
