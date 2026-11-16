# Optimal String Alignment & True Restricted Damerau-Levenshtein Solver (`damerau_levenshtein_osa`)

> Category: **String Matching & Edit Distance** | Language: **C++20**

## Overview

Computes both Optimal String Alignment (no substring edited twice) and true Lowrance-Wagner Damerau-Levenshtein edit distance permitting unrestricted adjacent character transpositions.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(M * N)` |
| **Space Complexity** | `O(M * N) full / O(min(M, N)) OSA strip` |

## Mathematical & Safety Invariants

- Metric symmetry holds: d(a, b) == d(b, a) for both OSA and true Damerau-Levenshtein.
- True Damerau-Levenshtein obeys triangle inequality d(a, c) <= d(a, b) + d(b, c).
- Restricted OSA equals or upper-bounds true Damerau-Levenshtein everywhere.

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
