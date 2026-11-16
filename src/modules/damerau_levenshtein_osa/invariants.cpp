#include "interface.hpp"

namespace codes_damerau_levenshtein_osa {
Status verify_dl_invariants(const std::string& a, const std::string& b, const std::string& c) {
    std::size_t ab = true_damerau_levenshtein(a, b);
    std::size_t ba = true_damerau_levenshtein(b, a);
    std::size_t bc = true_damerau_levenshtein(b, c);
    std::size_t ac = true_damerau_levenshtein(a, c);
    if (ab != ba || ac > ab + bc) return Status::InvariantViolation;
    std::size_t osa_ab = optimal_string_alignment(a, b);
    if (osa_ab < ab) return Status::InvariantViolation;
    return Status::Ok;
}
} // namespace codes_damerau_levenshtein_osa
