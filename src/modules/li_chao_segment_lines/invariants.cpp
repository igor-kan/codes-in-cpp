#include "interface.hpp"

namespace codes_li_chao_segment_lines {

void verify_module_postcondition(bool ok, const char* msg) {
    if (!ok) {
        throw std::logic_error(msg);
    }
}

} // namespace codes_li_chao_segment_lines
