# Binary Lifting Lowest Common Ancestor & Tree Distance Engine (`lca_binary_lifting`)

> Category: **Tree Algorithms** | Language: **C++20**

## Overview

Precomputes Euler tour entry/exit intervals and power-of-two ancestor tables to answer Lowest Common Ancestor (LCA), k-th ancestor, and shortest path length queries on rooted trees.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N log N) build, O(log N) query` |
| **Space Complexity** | `O(N log N)` |

## Mathematical & Safety Invariants

- Euler tour entry/exit intervals [tin, tout] nest cleanly: a is an ancestor of b iff tin[a] <= tin[b] and tout[b] <= tout[a].
- lca(u, v) is an ancestor of both u and v with maximal depth among common ancestors.

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
