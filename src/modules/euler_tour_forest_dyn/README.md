# Dynamic Tree Subtree Aggregate via Flattened Euler Tour (`euler_tour_forest_dyn`)

> Category: **Dynamic Trees** | Language: **C++20**

## Overview

Flattens rooted trees into entry/exit Euler tour intervals [tin[u], tout[u]] backed by a Fenwick tree to support O(log N) vertex weight updates and subtree sums.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) Euler flatten + O(log N) Fenwick subtree update & query` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Every subtree of vertex u occupies a contiguous interval [tin[u], tout[u]].
- Subtree sum equals sum of weights of all descendants of u.

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
