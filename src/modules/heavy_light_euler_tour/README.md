# Euler Tour Flattened Tree Subtree Range Engine (`heavy_light_euler_tour`)

> Category: **Tree & Range Structures** | Language: **C++20**

## Overview

Flattens rooted trees into contiguous Euler tin/tout entry-exit intervals backed by a Fenwick BIT for O(log N) subtree point/range sums.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) Euler flatten, O(log N) subtree add & query` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Subtree interval [tin[u], tout[u]] strictly contains every descendant of u.
- Tree-flattened subtree sum equals direct recursive DFS subtree sum.

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
