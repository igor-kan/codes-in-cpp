#include "interface.hpp"

namespace codes_graham_scan_hull_d58 {

void validate_problem_size(int n) {
    if (n <= 0) {
        throw std::invalid_argument("graham_scan_hull_d58: problem size must be positive");
    }
}

} // namespace codes_graham_scan_hull_d58
