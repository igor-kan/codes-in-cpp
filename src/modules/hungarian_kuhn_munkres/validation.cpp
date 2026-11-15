#include "interface.hpp"

namespace codes_hungarian_kuhn_munkres {
Status validate_cost_matrix(std::size_t rows, std::size_t cols, const std::vector<long long>& mat) {
    if (rows == 0 || cols == 0) return Status::NullOrEmpty;
    if (rows > cols || mat.size() != rows * cols) return Status::InvalidInput;
    return Status::Ok;
}
} // namespace codes_hungarian_kuhn_munkres
