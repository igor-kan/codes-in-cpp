#include "interface.hpp"

namespace codes_aho_corasick_flat_cpp {
void verify_ac_parity(const std::vector<std::string>& patterns, const std::string& text, int got) {
    int expected = 0;
    for (const auto& p : patterns) {
        std::size_t pos = text.find(p);
        while (pos != std::string::npos) {
            ++expected;
            pos = text.find(p, pos + 1);
        }
    }
    if (got != expected) throw std::logic_error("AC match count disagreed with substring oracle");
}
} // namespace codes_aho_corasick_flat_cpp
