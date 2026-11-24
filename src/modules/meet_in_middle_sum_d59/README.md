# Meet-in-the-Middle Exact Target Subset Sum (`meet_in_middle_sum_d59`)

> Category: **Search & Pruning** | Language: **C++20**

## Overview

Partitions integer multisets in half, enumerates exact left/right subset sums, and matches exact complements via sorted binary lookup.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N * 2^(N/2))` |
| **Space Complexity** | `O(2^(N/2))` |

## Mathematical & Safety Invariants

- Zero target always exists via empty subset while exact match beats naive exponent.

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
