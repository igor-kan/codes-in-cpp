# Monotonic Deque Convex Hull Trick for Linear-Slope DP Lower Envelope (`convex_hull_trick_deque`)

> Category: **Dynamic Programming Optimization** | Language: **C++20**

## Overview

Maintains the exact lower convex envelope of affine lines added in strictly decreasing slope order and queried in increasing x order in O(N) total time.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) amortized line insertion & monotonic abscissa query` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Emits exact minimum m*x + b without binary search when slopes and queries are monotonic.

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
