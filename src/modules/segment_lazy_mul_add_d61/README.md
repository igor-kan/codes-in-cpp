# Lazy Segment Tree with Composed Range Multiply and Range Add (`segment_lazy_mul_add_d61`)

> Category: **Segment Trees** | Language: **C++20**

## Overview

Composes affine range updates by storing each pending tag as a multiplier followed by an additive offset, so multiply and add operations merge without pushing to leaves eagerly.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) range multiply, range add, and range sum` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- Node sums equal exact element sums after any update sequence.
- Applying multiply m then add a maps x to x * m + a on every covered element.

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
