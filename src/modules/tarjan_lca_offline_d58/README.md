# Tarjan Offline DSU Lowest Common Ancestor Solver (`tarjan_lca_offline_d58`)

> Category: **Tree Offline Queries** | Language: **C++20**

## Overview

Answers batches of (u, v) lowest common ancestor tree queries in one DFS traversal via Disjoint Set Union subtree ancestor labeling.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O((V + Q) * alpha(V))` |
| **Space Complexity** | `O(V + Q)` |

## Mathematical & Safety Invariants

- Symmetric queries (u, v) and (v, u) return the identical tree ancestor cleanly.

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
