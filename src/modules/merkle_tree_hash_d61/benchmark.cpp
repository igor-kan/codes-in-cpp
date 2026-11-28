#include "interface.hpp"
#include <chrono>
#include <iostream>

int main() {
    using namespace codes_merkle_tree_hash_d61;
    std::vector<std::string> leaves = {"m1", "m2", "m3", "m4", "m5", "m6", "m7", "m8"};
    MerkleTree mt(leaves);
    auto t0 = std::chrono::steady_clock::now();
    volatile std::int64_t sink = 0;
    for (int iter = 0; iter < 500; ++iter) {
        auto proof = mt.proof(static_cast<std::size_t>(iter % 8));
    if (mt.verify(static_cast<std::size_t>(iter % 8), leaves[static_cast<std::size_t>(iter % 8)], proof)) sink = sink + 1;
    }
    auto t1 = std::chrono::steady_clock::now();
    auto us = std::chrono::duration_cast<std::chrono::microseconds>(t1 - t0).count();
    std::cout << "merkle_tree_hash_d61 us=" << us << " sink=" << sink << "\n";
    return 0;
}
