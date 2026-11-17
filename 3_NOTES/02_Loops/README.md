# 02_Loops - Loops - for, while, do-while, break/continue, typical patterns

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/01_input_output.cpp](../../2_BUILDING_BLOCKS/01_input_output.cpp)

```cpp
for (int i = 0; i < n; i++) { }          // known number of steps
while (condition) { }                    // may run 0 times
do { } while (condition);                // runs at least once (menus, "again?")
for (int x : arr) { }                    // range-for (copy)   for (int &x : arr) -> modify
break;     // leave the loop        continue;  // skip to the next iteration
while (n > 0) { digit = n % 10; n /= 10; }   // digits of a number
```

## Files

| File | What it shows | |
|---|---|---|
| [01_every_loop_detailed.cpp](01_every_loop_detailed.cpp) | for, multi-variable for, range-for, while, do-while, break, continue, nested loops, infinite loop + break, for-each by reference | ⭐ |
| [02_loops_over_arrays_and_vectors.cpp](02_loops_over_arrays_and_vectors.cpp) | for/while/do-while/range-for over static array, dynamic array and vector; min/max/sum/avg; bubble sort |  |
| [03_loop_patterns.cpp](03_loop_patterns.cpp) | loop PATTERNS you write again and again counting, sum/avg, digits of a number, reverse number, first match, flags, do-while menu, "repeat until valid" input, nested loop shapes | 🆕 added |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
