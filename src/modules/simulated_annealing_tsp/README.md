# 2-Opt Simulated Annealing Euclidean TSP Optimizer (`simulated_annealing_tsp`)

> Category: **Metaheuristics** | Language: **C++20**

## Overview

Minimizes closed Euclidean traveling salesperson tours via geometric cooling Simulated Annealing with O(1) 2-opt segment-reversal delta evaluation.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(Steps) incremental 2-opt edge delta evaluation` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Output tour is a valid permutation of [0, N).
- Final tour cost never exceeds initial tour length.

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
