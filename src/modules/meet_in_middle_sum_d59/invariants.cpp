#include "interface.hpp"

namespace codes_meet_in_middle_sum_d59 {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_meet_in_middle_sum_d59
