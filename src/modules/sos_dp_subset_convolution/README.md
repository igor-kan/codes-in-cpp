# Sum Over Subsets Zeta & Mobius Transform (`sos_dp_subset_convolution`)

> Category: **Bitmask DP** | Language: **C++20**

## Overview

Computes exact fast zeta (subset sum) and Mobius inverse transforms over K-bit boolean hypercubes so subset sums invert cleanly.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(K * 2^K)` |
| **Space Complexity** | `O(2^K)` |

## Mathematical & Safety Invariants

- Mobius transform strictly recovers the original coefficient vector after Zeta forward pass.

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
