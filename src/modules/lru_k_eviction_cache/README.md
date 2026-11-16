# Scan-Resistant LRU-K (K=2) Page Replacement Cache (`lru_k_eviction_cache`)

> Category: **Caching & Eviction Policies** | Language: **C++20**

## Overview

Maintains per-page 2-element backward reference timestamp windows so sequential cold scans are evicted prior to genuinely hot multi-reference pages.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(log N) lookup/evict via indexed history priority` |
| **Space Complexity** | `O(Capacity)` |

## Mathematical & Safety Invariants

- Live page count never exceeds cache capacity.
- Pages accessed only once carry infinite K-th backward distance and precede repeated hot pages during eviction.

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
