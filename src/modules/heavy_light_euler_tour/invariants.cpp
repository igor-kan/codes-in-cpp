#include "interface.hpp"

namespace codes_heavy_light_euler_tour {
void verify_euler_brackets(const EulerIndex& idx) {
    if (idx.tin.empty() || idx.tin[0] != 0 || idx.tout[0] != static_cast<int>(idx.tin.size()) - 1) {
        throw std::logic_error("root Euler interval must span [0, N-1]");
    }
}
} // namespace codes_heavy_light_euler_tour
