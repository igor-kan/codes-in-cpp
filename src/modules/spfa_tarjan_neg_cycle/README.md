# Shortest-Path Faster Algorithm with Predecessor Negative-Cycle Witness (`spfa_tarjan_neg_cycle`)

> Category: **Shortest Paths** | Language: **C++20**

## Overview

Relaxes directed weighted edges via FIFO queue while tracking relaxation depth len[v]; when len[v] >= V, walks parent pointers to extract an explicit negative cycle.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(V * E) queue-relaxed Bellman-Ford with cycle reconstruction` |
| **Space Complexity** | `O(V + E)` |

## Mathematical & Safety Invariants

- Extracted cycle vertices form a closed walk whose edge weights sum to < 0.

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
