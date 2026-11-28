# Bron-Kerbosch Pivot Maximal Clique Enumerator (`bron_kerbosch_clique_d61`)

> Category: **Graph Algorithms** | Language: **C++20**

## Overview

Enumerates all inclusion-maximal cliques with the Bron-Kerbosch recursion augmented by a pivot chosen to minimize branching over non-neighbors of the pivot.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(3^(N/3)) worst-case maximal clique enumeration` |
| **Space Complexity** | `O(N^2) adjacency matrix plus O(N) recursion depth` |

## Mathematical & Safety Invariants

- Every emitted set is a clique and cannot accept another adjacent vertex.
- No two emitted maximal cliques are identical.

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
