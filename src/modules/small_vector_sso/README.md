# Small-Buffer-Optimized Vector Container (Inline Capacity 16) (`small_vector_sso`)

> Category: **Memory & Containers** | Language: **C++20**

## Overview

Implements an inline-storage vector (SSO capacity 16) with Rule-of-Five copy/move semantics, aligned stack storage, and zero-allocation push/pop below threshold.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) Amortized push_back, O(N) spill` |
| **Space Complexity** | `O(1) heap bytes while size <= 16; O(N) after spill` |

## Mathematical & Safety Invariants

- data() points into the inline buffer whenever capacity() == 16.
- Promoting to heap preserves element order bit-for-bit and updates is_small() to false.
- Copy and move operations never alias heap storage after move-from cleanup.

## Module Architecture

| File | Lifecycle Role |
| :--- | :--- |
| `types.hpp` | Stage 01 |
| `errors.hpp` | Stage 02 |
| `interface.hpp` | Stage 03 |
| `core.cpp` | Stage 04 |
| `validation.cpp` | Stage 05 |
| `fast_path.cpp` | Stage 06 |
| `concurrent.cpp` | Stage 07 |
| `invariants.cpp` | Stage 08 |
| `unit_tests.cpp` | Stage 09 |
| `property_tests.cpp` | Stage 10 |
| `benchmark.cpp` | Stage 11 |
| `README.md` | Stage 12 |

## Verification & Execution Example

```text
g++ -std=c++20 -O2 -Wall -Wextra -Werror -pthread core.cpp validation.cpp fast_path.cpp concurrent.cpp invariants.cpp unit_tests.cpp -o test_bin && ./test_bin
```

---
© 2026 Igor Kan
