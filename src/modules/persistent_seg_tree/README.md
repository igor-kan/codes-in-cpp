# Path-Copying Persistent Segment Tree with Versioned Order Statistics (`persistent_seg_tree`)

> Category: **Persistent Data Structures** | Language: **C++20**

## Overview

Allocates O(log N) immutable copy-on-write tree nodes per point update, retaining every prior version snapshot for time-travel range sums and parallel range k-th order queries.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) per update and version query` |
| **Space Complexity** | `O(N + M log N) across M versions` |

## Mathematical & Safety Invariants

- Every historical version remains completely immutable after subsequent updates.
- Every internal node value equals the exact sum of its left and right children.

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
