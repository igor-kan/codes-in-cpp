#include "interface.hpp"

namespace codes_sos_dp_subset_convolution {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_sos_dp_subset_convolution
