#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_damerau_levenshtein_osa {
struct EditMetrics {
    std::size_t osa_distance = 0;
    std::size_t true_dl_distance = 0;
};
} // namespace codes_damerau_levenshtein_osa
