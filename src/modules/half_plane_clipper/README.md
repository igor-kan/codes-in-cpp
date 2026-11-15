# Half-Plane Intersection via Polar-Sorted Monotone Deque Clipping (`half_plane_clipper`)

> Category: **Computational Geometry** | Language: **C++20**

## Overview

Intersects N oriented 2D half-planes (defined as rays keeping the left half-plane) in O(N log N) using polar angle sorting and a convex-hull double-ended queue.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N log N) sorting + O(N) deque clipping` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Output vertices form a strictly counter-clockwise convex polygon containing zero vertices strictly outside any input half-plane.
- Polygon signed area via shoelace formula is strictly non-negative.

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
