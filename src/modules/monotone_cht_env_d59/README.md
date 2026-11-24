# Monotone Deque Convex Hull Trick Lower Envelope (`monotone_cht_env_d59`)

> Category: **DP Optimization** | Language: **C++20**

## Overview

Maintains lower convex envelope of decreasing-slope affine functions y = m*x + b supporting O(1) amortized non-decreasing x minimum evaluation.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) amortized push and monotone query` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Monotonic envelope matches quadratic exhaustive min(m*x + b) cleanly.

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
