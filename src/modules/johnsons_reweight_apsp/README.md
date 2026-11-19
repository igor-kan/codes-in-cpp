# Johnson O(V*E + V^2 log V) Reweighted All-Pairs Shortest Paths (`johnsons_reweight_apsp`)

> Category: **Shortest Paths** | Language: **C++20**

## Overview

Computes all-pairs shortest path distances in sparse graphs with negative edges (no negative cycles) by shifting edge weights with Bellman-Ford potentials h[v].

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(V*E + V*E log V) Bellman-Ford potentials + per-source Dijkstra` |
| **Space Complexity** | `O(V^2)` |

## Mathematical & Safety Invariants

- Reweighted edges w'(u,v) = w(u,v) + h[u] - h[v] >= 0 cleanly.

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
