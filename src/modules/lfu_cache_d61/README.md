# Capacity-Bounded Least-Frequently-Used Cache with Recency Tie-Break (`lfu_cache_d61`)

> Category: **Caches** | Language: **C++20**

## Overview

Evicts the resident key with the smallest access frequency, breaking ties by the least recently used timestamp, while tracking integer values in flat parallel arrays.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(C) lookup and eviction scan over capacity C` |
| **Space Complexity** | `O(C)` |

## Mathematical & Safety Invariants

- Resident key count never exceeds the configured capacity.
- Eviction always removes a minimum-frequency resident entry.

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
