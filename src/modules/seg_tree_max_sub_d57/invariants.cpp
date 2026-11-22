#include "interface.hpp"

namespace codes_seg_tree_max_sub_d57 {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_seg_tree_max_sub_d57
