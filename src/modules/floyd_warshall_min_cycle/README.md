# Floyd-Warshall APSP & Negative Cycle Probe (`floyd_warshall_min_cycle`)

> Category: **All-Pairs Shortest Paths** | Language: **C++20**

## Overview

Computes exact all-pairs shortest path distance matrices over weighted directed matrices and detects negative-weight cycles via main-diagonal inspection.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(V^3)` |
| **Space Complexity** | `O(V^2)` |

## Mathematical & Safety Invariants

- Absence of negative cycles preserves dist[i][i] == 0 across all vertices.

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
