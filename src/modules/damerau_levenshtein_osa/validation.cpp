#include "interface.hpp"

namespace codes_damerau_levenshtein_osa {
Status validate_strings(const std::string& a, const std::string& b) {
    if (a.size() > 65536 || b.size() > 65536) return Status::OutOfBounds;
    return Status::Ok;
}
} // namespace codes_damerau_levenshtein_osa
