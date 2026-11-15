# Implicit Treap Sequence Rope with Lazy Range Reversal (`treap_implicit_rope`)

> Category: **Randomized Balanced Trees** | Language: **C++20**

## Overview

Maintains an index-addressable dynamic sequence using SplitMix64 randomized heap priorities, supporting O(log N) split, merge, range sum queries, and lazy interval reversal.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) expected per split/merge/reverse` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Heap property holds strictly: every child priority is <= parent priority.
- Subtree size and aggregate sum fields equal the exact recursive sum over left and right children.

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
