# 05_Sorting_Searching - Sorting & searching - bubble, selection, insertion, quick, linear, sentinel, binary

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/04_sorting.cpp](../../2_BUILDING_BLOCKS/04_sorting.cpp) · [2_BUILDING_BLOCKS/03_arrays.cpp](../../2_BUILDING_BLOCKS/03_arrays.cpp)

The paste-ready, correct version of every algorithm below is in the building blocks (links at the top of this page). Every sort swaps by hand:

```cpp
int pomocnicza = tab[j];
tab[j] = tab[j + 1];
tab[j + 1] = pomocnicza;
```

| Algorithm | Idea | Cost |
|---|---|---|
| bubble | swap neighbours, biggest "bubbles" to the end; stop early if no swap | O(n²) |
| selection | find min of the unsorted part, swap it to position i | O(n²) |
| insertion | take next element, shift bigger ones right (or swap it left), insert | O(n²), fast if nearly sorted |
| quicksort | pivot, split into smaller / bigger, recurse | O(n log n) avg |
| linear search | check every element, return index or -1 | O(n) |
| sentinel search | put the searched value after the end, loop without `i < n` | O(n) |
| binary search | **sorted** data only, halve the range each step | O(log n) |

Descending order: flip `>` to `<` in the comparison (bubble/insertion) or pick the max instead of the min (selection).

## Files

| File | What it shows | |
|---|---|---|
| [01_insertion_sort_adjacent_swaps.cpp](01_insertion_sort_adjacent_swaps.cpp) | insertion sort done with adjacent swaps (correct) | 🔧 fixed |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [bubble_sort_polish_names.cpp](exercises/bubble_sort_polish_names.cpp) | bubble sort (Polish names) | 🔧 fixed |
| [selection_sort_count_div3.cpp](exercises/selection_sort_count_div3.cpp) | selection sort + count divisible by 3 | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
