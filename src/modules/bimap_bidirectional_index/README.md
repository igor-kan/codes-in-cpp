# Bidirectional 1-to-1 BiMap Index with Atomic Conflict Rollback (`bimap_bidirectional_index`)

> Category: **Associative Containers** | Language: **C++20**

## Overview

Maintains synchronized forward (K -> V) and reverse (V -> K) hash maps guaranteeing strict bijection parity with exception-safe rollback if a collision occurs mid-insertion.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(1) Average Forward/Reverse Lookup & Insert` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- forward.size() == reverse.size() at all quiescent states.
- Every forward entry (k, v) maps back via reverse[v] == k and vice versa.
- Rejecting a conflicting insert leaves pre-existing mappings completely untouched.

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
