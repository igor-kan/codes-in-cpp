#include "deutsch_jozsa_oracle.hpp"
#include <cassert>
#include <iostream>

int main() {
    std::vector<uint8_t> balanced = { 0, 1, 1, 0 };
    assert(evaluate_deutsch_jozsa_balanced(balanced) == true);
    std::vector<uint8_t> constant = { 1, 1, 1, 1 };
    assert(evaluate_deutsch_jozsa_balanced(constant) == false);
    std::cout << "test_deutsch_jozsa_oracle passed.\n";
    return 0;
}
