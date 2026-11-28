# Leftist Heap with Null-Path-Length Rank Melding (`leftist_heap_d61`)

> Category: **Meldable Heaps** | Language: **C++20**

## Overview

Keeps every node's right-spine null-path length at least as short as its left by swapping children after each meld, guaranteeing logarithmic right spines.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) meld and extract-min via right-spine rank` |
| **Space Complexity** | `O(N) node arena` |

## Mathematical & Safety Invariants

- Each node's left rank is never smaller than its right rank.
- Meld preserves the min-heap ordering at every parent-child edge.

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
