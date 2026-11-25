# Binary Lifting LCA and Euler Subtree Path Distance on Trees (`heavy_light_path_d60`)

> Category: **Tree Algorithms** | Language: **C++20**

## Overview

Builds ancestor jump tables, entry/exit Euler timestamps, and weighted prefix depths to answer arbitrary tree LCA and path distance queries.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N log N) lifting table build and O(log N) LCA` |
| **Space Complexity** | `O(N log N)` |

## Mathematical & Safety Invariants

- Path distance dist(u, v) equals depth[u] + depth[v] - 2 * depth[lca(u, v)].

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
