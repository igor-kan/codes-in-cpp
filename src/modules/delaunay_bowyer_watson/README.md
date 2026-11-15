# Bowyer-Watson Incremental 2D Delaunay Triangulation (`delaunay_bowyer_watson`)

> Category: **Computational Geometry** | Language: **C++20**

## Overview

Constructs the valid Delaunay triangulation of 2D point sets using Bowyer-Watson incremental cavity excavation, signed circumcircle predicates, and supertriangle stripping.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N^2) worst case, O(N log N) typical` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Every final triangle is oriented strictly counter-clockwise with positive area.
- Empty circumcircle property: no other input vertex lies strictly inside any triangle's circumcircle.

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
