#include "interface.hpp"

namespace codes_aho_corasick_flat_cpp {
void validate_patterns(const std::vector<std::string>& patterns) {
    if (patterns.empty()) throw std::invalid_argument("pattern list cannot be empty");
    for (const auto& p : patterns) {
        if (p.empty()) throw std::invalid_argument("empty pattern disallowed");
        for (char ch : p) {
            if (ch < 'a' || ch > 'z') throw std::invalid_argument("patterns must be lowercase a-z");
        }
    }
}
} // namespace codes_aho_corasick_flat_cpp
