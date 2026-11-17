# Dual-BIT Fenwick Tree for Range Increment & Range Sum (`fenwick_range_add_cpp`)

> Category: **Prefix & Range Structures** | Language: **C++20**

## Overview

Maintains two linked Fenwick trees representing linear prefix coefficients so arbitrary [l, r] interval increments and [l, r] interval sum queries complete in O(log N) time.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) per range_add and range_sum` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- range_sum(l, r) equals naive O(N) array sum after arbitrary sequences of range_add.

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
