# Kuhn-Munkres O(N^3) Hungarian Minimum-Cost Bipartite Assignment (`hungarian_min_assign_cpp`)

> Category: **Combinatorial Optimization** | Language: **C++20**

## Overview

Solves dense minimum-weight perfect bipartite assignment over N x N cost matrices in O(N^3) time with strict dual feasibility u[i] + v[j] <= cost[i][j].

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N^3) dual-potential shortest augmenting column match` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Dual potential sum equals exact minimum assignment primal cost.

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
