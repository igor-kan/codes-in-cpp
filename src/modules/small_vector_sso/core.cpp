#include "interface.hpp"
#include <algorithm>
#include <stdexcept>

namespace codes_small_vector_sso {
SmallVecInt::~SmallVecInt() {
    if (!is_small()) delete[] ptr;
}

SmallVecInt::SmallVecInt(const SmallVecInt& other) {
    reserve(other.cap);
    for (std::size_t i = 0; i < other.len; ++i) ptr[i] = other.ptr[i];
    len = other.len;
}

SmallVecInt::SmallVecInt(SmallVecInt&& other) noexcept {
    if (other.is_small()) {
        for (std::size_t i = 0; i < other.len; ++i) inline_buf[i] = other.inline_buf[i];
        ptr = inline_buf;
        cap = kInlineCap;
        len = other.len;
    } else {
        ptr = other.ptr;
        cap = other.cap;
        len = other.len;
        other.ptr = other.inline_buf;
        other.cap = kInlineCap;
        other.len = 0;
    }
}

SmallVecInt& SmallVecInt::operator=(const SmallVecInt& other) {
    if (this == &other) return *this;
    clear();
    reserve(other.len);
    for (std::size_t i = 0; i < other.len; ++i) ptr[i] = other.ptr[i];
    len = other.len;
    return *this;
}

SmallVecInt& SmallVecInt::operator=(SmallVecInt&& other) noexcept {
    if (this == &other) return *this;
    if (!is_small()) delete[] ptr;
    if (other.is_small()) {
        ptr = inline_buf;
        cap = kInlineCap;
        len = other.len;
        for (std::size_t i = 0; i < len; ++i) inline_buf[i] = other.inline_buf[i];
    } else {
        ptr = other.ptr;
        cap = other.cap;
        len = other.len;
        other.ptr = other.inline_buf;
        other.cap = kInlineCap;
        other.len = 0;
    }
    return *this;
}

void SmallVecInt::reserve(std::size_t new_cap) {
    if (new_cap <= cap) return;
    std::size_t alloc_cap = std::max(new_cap, cap * 2);
    int64_t* next = new int64_t[alloc_cap];
    for (std::size_t i = 0; i < len; ++i) next[i] = ptr[i];
    if (!is_small()) delete[] ptr;
    ptr = next;
    cap = alloc_cap;
}

void SmallVecInt::push_back(int64_t v) {
    if (len == cap) reserve(cap * 2);
    ptr[len++] = v;
}

void SmallVecInt::pop_back() {
    if (len == 0) throw std::out_of_range("empty SmallVecInt");
    --len;
}

void SmallVecInt::clear() { len = 0; }
} // namespace codes_small_vector_sso
