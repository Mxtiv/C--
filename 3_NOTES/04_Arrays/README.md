# 04_Arrays - Arrays - static, dynamic (new[]), 2D, min/max/sum/average

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/03_arrays.cpp](../../2_BUILDING_BLOCKS/03_arrays.cpp)

```cpp
int t[5] = {1, 2, 3};          // rest are 0; indexes 0..4 (FIRST INDEX IS 0!)
const int N = 10; int a[N];    // size must be a constant
int n = sizeof(t) / sizeof(t[0]);      // element count (only for real arrays)
int *d = new int[n];  ...  delete[] d; // size known at runtime
int m[3][4];  m[row][col]              // 2D;  void f(int m[][4], int rows)
int mn = a[0]; for (int i = 1; i < n; i++) if (a[i] < mn) mn = a[i];   // min pattern
double avg = (double)sum / n;          // cast, otherwise integer division
```

## Files

| File | What it shows | |
|---|---|---|
| [01_overview_arrays.cpp](01_overview_arrays.cpp) | static + dynamic arrays: random fill, print, min, max, sum, average, bubble/insertion/selection sort, std::sort | ⭐ |
| [02_2d_array_fill_print.cpp](02_2d_array_fill_print.cpp) | 2D array int tab[2][3]: passing to a function, random fill, print | 🔧 fixed |
| [03_2d_array_operations.cpp](03_2d_array_operations.cpp) | 2D arrays - declare, init, pass to function, row/column sums, max element with position, diagonal, dynamic 2D array, vector of vectors | 🆕 added |
| [04_dynamic_array_from_input_average.cpp](04_dynamic_array_from_input_average.cpp) | new double[size] with size from user, average, delete[] |  |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [2d_array_task.cpp](exercises/2d_array_task.cpp) | 2D array random fill + print | 🔧 fixed |
| [min_max_functions.cpp](exercises/min_max_functions.cpp) | random fill + min/max element functions | 🔧 fixed |
| [random_array_count_div3_min.cpp](exercises/random_array_count_div3_min.cpp) | const size array, random 10-20, count divisible by 3, minimum | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
