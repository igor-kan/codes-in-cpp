# Rubinchik-Shur Eertree Palindromic Automaton (`palindromic_tree_eertree`)

> Category: **String Automata** | Language: **C++20**

## Overview

Maintains two roots (length -1 imaginary and length 0 empty) and palindrome suffix links to discover all distinct palindromic substrings online in O(N) time.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) online distinct palindrome insertion & suffix-link traversal` |
| **Space Complexity** | `O(N) states` |

## Mathematical & Safety Invariants

- Number of created non-root states equals exact number of distinct palindromic substrings.

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
