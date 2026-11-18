# Weight-Balanced Scapegoat Tree with Flat-Array Rebuild (`scapegoat_weight_bst`)

> Category: **Balanced Search Trees** | Language: **C++20**

## Overview

Maintains height balance without per-node color or rotation metadata by detecting alpha-weight-unbalanced ancestors and flattening/rebuilding subtrees in O(k).

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) amortized insert and rank/order-statistic lookup` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- In-order traversal is strictly sorted.
- Tree height stays bounded by log_{1/alpha}(N) + 1.

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
