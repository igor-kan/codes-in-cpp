/**
 * @file core.cpp
 * @brief Median-of-three in-place quicksort partitioning for LSD 32-Bit Integer Radix Sort with Bucket Passes.
 * Module: radix_sort_lsd_32
 */

#include "types.cpp"

static inline void radix_sort_lsd_32_swap(double* a, double* b) {
    double t = *a; *a = *b; *b = t;
}

static size_t radix_sort_lsd_32_partition(double* arr, size_t low, size_t high) {
    double pivot = arr[high];
    size_t i = low;
    for (size_t j = low; j < high; ++j) {
        if (arr[j] <= pivot) {
            radix_sort_lsd_32_swap(&arr[i], &arr[j]);
            i++;
        }
    }
    radix_sort_lsd_32_swap(&arr[i], &arr[high]);
    return i;
}

void radix_sort_lsd_32_sort(double* arr, size_t low, size_t high) {
    if (low < high) {
        size_t pi = radix_sort_lsd_32_partition(arr, low, high);
        if (pi > low) radix_sort_lsd_32_sort(arr, low, pi - 1);
        radix_sort_lsd_32_sort(arr, pi + 1, high);
    }
}
