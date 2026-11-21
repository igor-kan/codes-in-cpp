#include "interface.hpp"
#include <algorithm>
#include <cmath>
#include <limits>
#include <numeric>
#include <queue>

namespace codes_sos_dp_subset_convolution {

std::vector<long long> sos_zeta(std::vector<long long> f, int bits) {
    if (bits < 0 || bits > 18 || f.size() != (1ULL << bits)) throw std::invalid_argument("size mismatch");
    for (int b = 0; b < bits; ++b) {
        for (std::size_t mask = 0; mask < f.size(); ++mask) {
            if (mask & (1ULL << b)) f[mask] += f[mask ^ (1ULL << b)];
        }
    }
    return f;
}

std::vector<long long> sos_mobius(std::vector<long long> f, int bits) {
    if (bits < 0 || bits > 18 || f.size() != (1ULL << bits)) throw std::invalid_argument("size mismatch");
    for (int b = 0; b < bits; ++b) {
        for (std::size_t mask = 0; mask < f.size(); ++mask) {
            if (mask & (1ULL << b)) f[mask] -= f[mask ^ (1ULL << b)];
        }
    }
    return f;
}

} // namespace codes_sos_dp_subset_convolution
