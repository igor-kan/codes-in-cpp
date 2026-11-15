# Nelder-Mead Derivative-Free Downhill Simplex Optimizer (`nelder_mead_simplex`)

> Category: **Numerical Optimization** | Language: **C++20**

## Overview

Minimizes arbitrary smooth or non-smooth D-dimensional objectives without gradients using Nelder-Mead centroid reflection, expansion, contraction, and simplex shrinkage.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(K * D^2) across K simplex iterations in R^D` |
| **Space Complexity** | `O(D^2)` |

## Mathematical & Safety Invariants

- The best simplex vertex value f_best is strictly non-increasing across iterations.
- Every simplex vertex maintains exact dimensionality D matching initial guess.

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
