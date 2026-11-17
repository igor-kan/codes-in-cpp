# Arena-Indexed Deterministic Ordered Skip List in C++20 (`skiplist_index_cpp`)

> Category: **Ordered Indexes** | Language: **C++20**

## Overview

Implements an ordered key-value index over multi-level forward skip towers backed by contiguous arena vector storage for cache-friendly lookup and range enumeration.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) expected search, insertion, and lower_bound range scan` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Level-0 forward chain traverses all stored keys in strictly increasing order.
- Every higher level k > 0 is a sorted subsequence of level k - 1.

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
