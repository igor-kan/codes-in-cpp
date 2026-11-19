#include "interface.hpp"

namespace codes_convex_hull_trick_deque {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_convex_hull_trick_deque
