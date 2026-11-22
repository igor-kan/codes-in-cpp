# Prefix-Doubling Suffix Array & Binary Substring Query (`suffix_array_doubling_d57`)

> Category: **Suffix Data Structures** | Language: **C++20**

## Overview

Builds sorted suffix start permutations via k-doubling rank tuples and searches arbitrary pattern strings in lexicographic suffix order.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N log^2 N) build, O(M log N) query` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Returned suffix permutation sorts all suffixes strictly lexicographically.

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
