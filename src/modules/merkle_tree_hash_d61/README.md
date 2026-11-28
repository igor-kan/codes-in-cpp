# Merkle Hash Tree with Membership Proof Verification (`merkle_tree_hash_d61`)

> Category: **Hashing** | Language: **C++20**

## Overview

Builds a binary Merkle tree by combining FNV-1a leaf digests with an order-sensitive mixer and emits sibling paths that recompute the root for inclusion proofs.

## Complexity Guarantees

| Metric | Asymptotic Bound |
| :--- | :--- |
| **Time Complexity** | `O(N) tree build and O(log N) inclusion proof` |
| **Space Complexity** | `O(N)` |

## Mathematical & Safety Invariants

- A valid proof for a stored leaf always reproduces the root digest.
- A tampered leaf or sibling breaks the recomputed root.

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
