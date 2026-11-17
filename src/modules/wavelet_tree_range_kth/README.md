# Static Wavelet Tree for O(log Sigma) Range K-th & Rank Queries (`wavelet_tree_range_kth`)

> Category: **Succinct Range Structures** | Language: **C++20**

## Overview

Partitions bounded integer arrays recursively by value midpoints, storing prefix-count bit arrays at each node to answer online range K-th order statistics and value counts.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N log V) build, O(log V) range_kth and range_freq` |
| **Space Complexity** | `O(N log V)` |

## Mathematical & Safety Invariants

- range_kth(l, r, k) matches k-th element of std::sort on slice [l, r).
- range_freq(l, r, x) matches exact linear occurrence count.

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
