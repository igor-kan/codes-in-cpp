# Chtholly Interval-Assignment Tree with Range Sum Queries (`chtholly_tree_d61`)

> Category: **Interval Structures** | Language: **C++20**

## Overview

Maintains a partition of an index range into disjoint constant-valued intervals so that a bulk assignment replaces overlapping pieces and range sums aggregate covered pieces.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(K log K) assignment rewrite and O(K) range aggregation` |
| **Space Complexity** | `O(K) disjoint intervals` |

## Mathematical & Safety Invariants

- Stored intervals are disjoint and sorted by left endpoint.
- Every range sum equals the sum of the current assigned values.

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
