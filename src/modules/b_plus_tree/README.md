# Cacheline-Sized Node B+ Tree for Ordered Storage (`b_plus_tree`)

## Overview

The `b_plus_tree` module provides high-performance, mathematically rigorous operations for `codes-in-cpp`.

### Component Artifacts

- **Type Definitions**: [`types.cpp`](./types.cpp)
- **Computational Core**: [`core.cpp`](./core.cpp)
- **Deterministic Unit Tests**: [`tests.cpp`](./tests.cpp)
- **SIMD Optimizations**: [`perf_simd.cpp`](./perf_simd.cpp)
- **Microbenchmarks**: [`benchmarks.cpp`](./benchmarks.cpp)
- **Boundary Validation**: [`boundary.cpp`](./boundary.cpp)
- **Property Fuzzing**: [`fuzz_invariants.cpp`](./fuzz_invariants.cpp)

### Computational Invariant

$$f(x) = x \left(1 + \frac{1}{2}x - \frac{1}{8}x^2\right)$$

Maintained under strict continuous integration, sanitizer checks, and memory bounds verification.
