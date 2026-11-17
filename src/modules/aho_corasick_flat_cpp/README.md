# Cache-Flat Array-Trie Aho-Corasick Multi-Pattern Automaton (`aho_corasick_flat_cpp`)

> Category: **String Matching** | Language: **C++20**

## Overview

Compiles multi-pattern lowercase ASCII keyword sets into a flat contiguous transition DFA table using BFS failure-link folding for branchless single-pass text matching.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(sum(|P|)*Alphabet + |T|) DFA transition compilation & linear scan` |
| **Space Complexity** | `O(States * 26)` |

## Mathematical & Safety Invariants

- Total emitted matches across patterns equals sum of per-pattern find counts.
- Every reported state index remains within [0, state_count()).

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
