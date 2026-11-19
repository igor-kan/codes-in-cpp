# Arena-Backed Persistent Segment Tree for Static Range K-th Order (`persistent_segtree_kth`)

> Category: **Persistent Data Structures** | Language: **C++20**

## Overview

Maintains versioned frequency segment trees across array prefixes using path-copying arena allocation to answer arbitrary subarray [L, R] K-th smallest queries.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O((N + Q) log N) functional prefix version tree & descent` |
| **Space Complexity** | `O(N log N) nodes` |

## Mathematical & Safety Invariants

- Difference of prefix versions root[R+1] - root[L] yields exact subarray histogram.

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
