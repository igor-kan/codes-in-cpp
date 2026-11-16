#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <string>
#include <array>
#include <functional>
#include <utility>

namespace codes_small_vector_sso {
struct SmallVecInt {
    static constexpr std::size_t kInlineCap = 16;
    alignas(int64_t) int64_t inline_buf[kInlineCap]{};
    int64_t* ptr = inline_buf;
    std::size_t len = 0;
    std::size_t cap = kInlineCap;

    SmallVecInt() = default;
    ~SmallVecInt();
    SmallVecInt(const SmallVecInt& other);
    SmallVecInt(SmallVecInt&& other) noexcept;
    SmallVecInt& operator=(const SmallVecInt& other);
    SmallVecInt& operator=(SmallVecInt&& other) noexcept;

    bool is_small() const { return ptr == inline_buf; }
    void push_back(int64_t v);
    void pop_back();
    void reserve(std::size_t new_cap);
    void clear();
};
} // namespace codes_small_vector_sso
