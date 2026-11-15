# Kuhn-Munkres Hungarian Minimum-Cost Bipartite Assignment Solver (`hungarian_kuhn_munkres`)

> Category: **Combinatorial Optimization** | Language: **C++20**

## Overview

Computes exact minimum-weight perfect matching in bipartite graphs using 1-indexed potentials u/v, augmenting path tracking, and dual slack minimization.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N^3)` |
| **Space Complexity** | `O(N^2)` |

## Mathematical & Safety Invariants

- Output assignment is a valid bijection over rows 0..N-1 to columns 0..M-1.
- Strong LP duality holds: primal assignment cost equals sum(u) + sum(v) dual objective.

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
