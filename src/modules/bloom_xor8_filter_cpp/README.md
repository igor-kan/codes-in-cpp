# Static Graf-Lemire Xor8 Immutable Filter via Peeling (`bloom_xor8_filter_cpp`)

> Category: **Probabilistic Structures** | Language: **C++20**

## Overview

Builds static Graf-Lemire Xor8 membership filters over 64-bit keys using 3-choice cuckoo hypergraph peeling and exact reverse fingerprint assignment for ~1/256 false positive rate.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) expected hypergraph peeling build, O(1) 3-probe XOR query` |
| **Space Complexity** | `~1.23 * N bytes (exact 8-bit fingerprints)` |

## Mathematical & Safety Invariants

- Zero false negatives across 100% of inserted unique keys.
- Table length equals 3 * seg_len and is a strict multiple of 3.

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
