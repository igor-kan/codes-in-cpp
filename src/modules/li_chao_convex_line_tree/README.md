# Li Chao Segment Tree Minimum Envelope (`li_chao_convex_line_tree`)

> Category: **Convex Hull Trick** | Language: **C++20**

## Overview

Maintains the lower envelope of linear functions y = m*x + b over a discrete integer coordinate range [0, MAX_X] without requiring monotonic slopes.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log R) per line insertion or point evaluation` |
| **Space Complexity** | `O(R)` |

## Mathematical & Safety Invariants

- Evaluated y(x) equals min_i(m_i * x + b_i) over all inserted lines.

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
