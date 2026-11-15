# Damped Levenberg-Marquardt / Gauss-Newton Nonlinear Least Squares (`gauss_newton_nonlinear`)

> Category: **Numerical Optimization** | Language: **C++20**

## Overview

Fits nonlinear parametric residual models r(theta) = 0 using adaptive Levenberg-Marquardt damping over finite-difference Jacobians and partial-pivoted normal equations.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(K * (M * P^2 + P^3)) for M residuals and P parameters` |
| **Space Complexity** | `O(M * P + P^2)` |

## Mathematical & Safety Invariants

- Sum-of-squared residuals SSR after an accepted step is strictly <= previous SSR.
- Parameter vector dimension matches problem dimension throughout iteration.

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
