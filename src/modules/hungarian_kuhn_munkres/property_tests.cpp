#include "interface.hpp"
#include <algorithm>
#include <cassert>
#include <limits>
#include <numeric>

int main() {
    using namespace codes_hungarian_kuhn_munkres;
    std::size_t n = 5;
    std::vector<long long> mat(n * n);
    for (std::size_t i = 0; i < n * n; ++i) mat[i] = static_cast<long long>((i * 17 + 5) % 29) - 4;
    auto res = solve_hungarian(n, n, mat);
    assert(verify_assignment_bijection(n, n, mat, res) == Status::Ok);
    std::vector<std::size_t> perm(n);
    std::iota(perm.begin(), perm.end(), 0);
    long long brute = std::numeric_limits<long long>::max();
    do {
        brute = std::min(brute, evaluate_assignment_cost(n, mat, perm));
    } while (std::next_permutation(perm.begin(), perm.end()));
    assert(res.min_cost == brute);
    return 0;
}
