#include "interface.hpp"

namespace codes_treap_implicit_rev_d58 {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_treap_implicit_rev_d58
