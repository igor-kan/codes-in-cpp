#include "interface.hpp"

namespace codes_knuth_yao_quadrangle_dp {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_knuth_yao_quadrangle_dp
