# Tarjan Lowlink Cut-Edge Bridges & 2-Edge-Connected Analyzer (`tarjan_bridge_bcc_cpp`)

> Category: **Graph Connectivity** | Language: **C++20**

## Overview

Identifies all cut-edges (bridges) in undirected multigraphs via Tarjan discovery and lowlink propagation: an edge (u, v) is a bridge iff low[v] > tin[u].

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(V + E) single-pass DFS lowlink bridge detection` |
| **Space Complexity** | `O(V + E)` |

## Mathematical & Safety Invariants

- Removal of any reported bridge disconnects the graph; cycle edges are never bridges.

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
