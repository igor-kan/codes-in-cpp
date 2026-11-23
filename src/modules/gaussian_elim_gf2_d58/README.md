# GF(2) XOR Vector Space Linear Basis Max-Subset (`gaussian_elim_gf2_d58`)

> Category: **Linear Algebra GF(2)** | Language: **C++20**

## Overview

Maintains an echelon-reduced 60-bit XOR basis over non-negative uint64 integers to maximize subset XOR sums cleanly.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(60 * N)` |
| **Space Complexity** | `O(60)` |

## Mathematical & Safety Invariants

- Optimal subset XOR strictly dominates every single basis/input element cleanly.

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
