# One-Pass Dynamic FGK/Vitter Adaptive Huffman Tree Codec (`huffman_adaptive_vitter`)

> Category: **Data Compression** | Language: **C++20**

## Overview

Maintains a dynamic adaptive Huffman binary tree with NYT (Not Yet Transmitted) sentinel splitting and sibling-property block weight promotions during single-pass compression and exact decompression.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(CodeLength) per symbol encode/decode` |
| **Space Complexity** | `O(Alphabet = 256)` |

## Mathematical & Safety Invariants

- Tree obeys the sibling property: weights strictly non-decreasing in block order numbers 0..512.
- Decoding the transmitted bitstream on a synchronized decoder yields byte-for-byte identity.

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
