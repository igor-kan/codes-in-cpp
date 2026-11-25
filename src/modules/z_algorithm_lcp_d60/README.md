# Gusfield Z-Array Linear Pattern Occurrence Locator (`z_algorithm_lcp_d60`)

> Category: **String Algorithms** | Language: **C++20**

## Overview

Computes Z[i] = LCP(S, S[i..]) in linear time using an active [L, R] Z-box window and locates exact pattern occurrences.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N + M) Z-box prefix match computation` |
| **Space Complexity** | `O(N + M)` |

## Mathematical & Safety Invariants

- Every Z[i] equals exact longest common prefix of S and S[i..].

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
