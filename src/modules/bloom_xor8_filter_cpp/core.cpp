#include "interface.hpp"
#include <algorithm>
#include <limits>
#include <numeric>

namespace codes_bloom_xor8_filter_cpp {

static std::uint64_t mix64(std::uint64_t k) {
    k = (k ^ (k >> 30)) * 0xbf58476d1ce4e5b9ULL;
    k = (k ^ (k >> 27)) * 0x94d049bb133111ebULL;
    return k ^ (k >> 31);
}

static std::uint64_t rotl64(std::uint64_t n, unsigned int c) {
    return (n << c) | (n >> (64 - c));
}

static void h012(std::uint64_t hash, std::size_t block_len, std::size_t& h0, std::size_t& h1, std::size_t& h2) {
    std::uint32_t r0 = static_cast<std::uint32_t>(hash);
    std::uint32_t r1 = static_cast<std::uint32_t>(rotl64(hash, 21));
    std::uint32_t r2 = static_cast<std::uint32_t>(rotl64(hash, 42));
    h0 = (static_cast<std::uint64_t>(r0) * block_len) >> 32;
    h1 = block_len + ((static_cast<std::uint64_t>(r1) * block_len) >> 32);
    h2 = 2 * block_len + ((static_cast<std::uint64_t>(r2) * block_len) >> 32);
}

static std::uint8_t fp8(std::uint64_t hash) {
    return static_cast<std::uint8_t>(hash ^ (hash >> 32));
}

Xor8Filter build_xor8_filter(const std::vector<std::uint64_t>& keys_in) {
    std::vector<std::uint64_t> keys = keys_in;
    std::sort(keys.begin(), keys.end());
    keys.erase(std::unique(keys.begin(), keys.end()), keys.end());
    validate_unique_keys(keys);

    std::size_t cap = std::max<std::size_t>(32, static_cast<std::size_t>(1.25 * static_cast<double>(keys.size()) + 24));
    std::size_t block_len = cap / 3;
    std::size_t size = 3 * block_len;
    std::uint64_t seed = 0x123456789ABCDEF0ULL;

    for (int attempt = 0; attempt < 32; ++attempt) {
        std::vector<std::uint64_t> xormask(size, 0);
        std::vector<int> count(size, 0);
        for (auto k : keys) {
            std::uint64_t h = mix64(k + seed);
            std::size_t i0, i1, i2;
            h012(h, block_len, i0, i1, i2);
            xormask[i0] ^= h; ++count[i0];
            xormask[i1] ^= h; ++count[i1];
            xormask[i2] ^= h; ++count[i2];
        }
        std::vector<std::size_t> q;
        q.reserve(size);
        for (std::size_t i = 0; i < size; ++i) {
            if (count[i] == 1) q.push_back(i);
        }
        std::vector<std::pair<std::uint64_t, std::size_t>> stack;
        stack.reserve(keys.size());
        std::size_t head = 0;
        while (head < q.size()) {
            std::size_t idx = q[head++];
            if (count[idx] != 1) continue;
            std::uint64_t h = xormask[idx];
            stack.emplace_back(h, idx);
            std::size_t i0, i1, i2;
            h012(h, block_len, i0, i1, i2);
            for (std::size_t pos : {i0, i1, i2}) {
                xormask[pos] ^= h;
                --count[pos];
                if (count[pos] == 1) q.push_back(pos);
            }
        }
        if (stack.size() == keys.size()) {
            std::vector<std::uint8_t> B(size, 0);
            for (int si = static_cast<int>(stack.size()) - 1; si >= 0; --si) {
                std::uint64_t h = stack[static_cast<std::size_t>(si)].first;
                std::size_t slot = stack[static_cast<std::size_t>(si)].second;
                std::size_t i0, i1, i2;
                h012(h, block_len, i0, i1, i2);
                B[slot] = fp8(h) ^ B[i0] ^ B[i1] ^ B[i2];
            }
            return {seed, block_len, std::move(B)};
        }
        seed += 0x9e3779b97f4a7c15ULL;
    }
    throw std::runtime_error("Xor8 peeling failed after 32 seed attempts");
}

bool xor8_contains(const Xor8Filter& f, std::uint64_t key) {
    std::uint64_t h = mix64(key + f.seed);
    std::size_t i0, i1, i2;
    h012(h, f.block_len, i0, i1, i2);
    return (f.fingerprints[i0] ^ f.fingerprints[i1] ^ f.fingerprints[i2]) == fp8(h);
}

} // namespace codes_bloom_xor8_filter_cpp
