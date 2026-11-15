# Self-Adjusting Bottom-Up Splay Tree with Order Statistics (`splay_tree_amortized`)

> Category: **Amortized Search Trees** | Language: **C++20**

## Overview

Implements Sleator-Tarjan self-adjusting binary search tree using Zig, Zig-Zig, and Zig-Zag rotations to bring accessed nodes to the root while maintaining subtree sizes.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) amortized per access/insert/erase` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Strict symmetric in-order BST key ordering holds across all non-null nodes.
- Parent links are mutually consistent with left/right child pointers.

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
