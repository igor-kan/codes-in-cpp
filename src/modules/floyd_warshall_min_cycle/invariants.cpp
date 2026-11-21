#include "interface.hpp"

namespace codes_floyd_warshall_min_cycle {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_floyd_warshall_min_cycle
