# Fractional Cascading Multi-Catalog Simultaneous Lower-Bound Search (`fractional_cascading_grid`)

> Category: **Geometric Data Structures** | Language: **C++20**

## Overview

Augments K sorted catalogs by propagating every second element upward from catalog i+1 into catalog i with direct forward pointers for O(log N + K) queries.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N + K) simultaneous lower-bound lookup across K sorted catalogs` |
| **Space Complexity** | `O(K * N)` |

## Mathematical & Safety Invariants

- Every catalog i returns the exact first element >= query x.

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
