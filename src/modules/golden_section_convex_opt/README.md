# Golden-Section & Parabolic Unimodal Continuous Minimizer (`golden_section_convex_opt`)

> Category: **Numerical Optimization** | Language: **C++20**

## Overview

Minimizes strictly unimodal 1D real functions on [a, b] without derivatives by reusing interior golden-ratio probes phi = (sqrt(5)-1)/2.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log((b - a) / tol)) conjugate golden-ratio bracket reduction` |
| **Space Complexity** | `O(1)` |

## Mathematical & Safety Invariants

- Bracket width shrinks by factor 0.6180339887 at every iteration.
- Converged minimizer x* lies within tol of true analytical minimum.

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
