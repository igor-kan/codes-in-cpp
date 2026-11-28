# Gale-Shapley Deferred-Acceptance Stable Matching (`stable_marriage_gale_d61`)

> Category: **Matching** | Language: **C++20**

## Overview

Computes a stable perfect matching by letting proposers issue preferences in order while receivers defer acceptance to the best proposal seen so far, using a rank table for constant-time comparisons.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N^2) proposals with O(1) rank comparisons` |
| **Space Complexity** | `O(N^2) preference rank matrix` |

## Mathematical & Safety Invariants

- The result is a permutation assigning every vertex one partner.
- No unmatched proposer-receiver pair mutually prefers each other.

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
