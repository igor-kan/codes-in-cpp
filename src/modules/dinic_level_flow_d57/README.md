# Dinic Blocking-Flow & Layered Network Max-Flow (`dinic_level_flow_d57`)

> Category: **Network Flows** | Language: **C++20**

## Overview

Computes exact maximum s-t flow using BFS level layering paired with current-arc pruned DFS blocking-flow passes across residual edges.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(E * V^2) general, O(E * sqrt(V)) unit networks` |
| **Space Complexity** | `O(V + E)` |

## Mathematical & Safety Invariants

- Saturated min-cut blocks all augmenting paths leaving source s in the level graph.

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
