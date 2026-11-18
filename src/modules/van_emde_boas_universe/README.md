# Recursive Van Emde Boas Tree over 16-Bit Integer Universe (`van_emde_boas_universe`)

> Category: **Sub-Logarithmic Structures** | Language: **C++20**

## Overview

Partitions a universe of size U = 2^16 recursively into sqrt(U) clusters and a summary vEB structure to support O(log log U) successor queries.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log log U) insert, delete, successor, and predecessor` |
| **Space Complexity** | `O(U)` |

## Mathematical & Safety Invariants

- min_val and max_val bound all active keys in every cluster.
- Successor returns strictly smallest element > x or -1.

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
