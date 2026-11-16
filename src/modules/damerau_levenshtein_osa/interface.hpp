#pragma once
#include "types.hpp"
#include "errors.hpp"

namespace codes_damerau_levenshtein_osa {
std::size_t optimal_string_alignment(const std::string& a, const std::string& b);
std::size_t true_damerau_levenshtein(const std::string& a, const std::string& b);
Status validate_strings(const std::string& a, const std::string& b);
std::vector<EditMetrics> batch_edit_distances(const std::vector<std::pair<std::string, std::string>>& pairs);
Status verify_dl_invariants(const std::string& a, const std::string& b, const std::string& c);
} // namespace codes_damerau_levenshtein_osa
