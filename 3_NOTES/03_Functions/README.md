# 03_Functions - Functions - prototypes, parameters, overloading, recursion, lambdas

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/05_numbers.cpp](../../2_BUILDING_BLOCKS/05_numbers.cpp)

```cpp
int add(int a, int b);                   // prototype (declaration) above main
int add(int a, int b) { return a + b; }  // definition
void f(int x)          // by value - works on a COPY
void f(int &x)         // by reference - changes the caller's variable ("returns" values)
void f(const string &s)// by const reference - no copy, read-only (strings, objects)
void f(int *p)         // by pointer - call with f(&x), use *p
void f(int arr[], int n)               // arrays always need the size passed too
void line(char c = '-', int n = 20);   // default arguments (in the prototype)
int fact(int n) { return n <= 1 ? 1 : n * fact(n - 1); }   // recursion needs a base case
auto sq = [](int x) { return x * x; }; // lambda
```
Overloading = same name, different parameter list (number or types). Return type alone is not enough.

## Files

| File | What it shows | |
|---|---|---|
| [01_function_basics.cpp](01_function_basics.cpp) | function basics - prototype vs definition, return values, void, parameters, default arguments, passing arrays, returning several values, static local, const parameters | ⭐ 🆕 added |
| [02_pass_by_value_reference_pointer.cpp](02_pass_by_value_reference_pointer.cpp) | the same function written 4 ways: by value, by reference (output params), by const reference, by pointer | ⭐ |
| [03_function_overloading.cpp](03_function_overloading.cpp) | overloading: print(int), print(double), print(string), print(int,int) |  |
| [04_inline_functions.cpp](04_inline_functions.cpp) | inline functions |  |
| [05_lambda_as_local_function.cpp](05_lambda_as_local_function.cpp) | global function vs lambda used as a "local function" |  |
| [06_recursion_factorial.cpp](06_recursion_factorial.cpp) | recursive factorial with base case |  |
| [07_factorial_iterative.cpp](07_factorial_iterative.cpp) | factorial with a loop (iterative) |  |
| [08_recursion_print_1_to_n.cpp](08_recursion_print_1_to_n.cpp) | recursion: print 1..n (recursive call BEFORE printing) |  |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [overloading_powieksz.cpp](exercises/overloading_powieksz.cpp) | overloads powieksz(int), (int,int), (float) |  |
| [recursion_sequence_2x_minus_4.cpp](exercises/recursion_sequence_2x_minus_4.cpp) | recursive sequence attempt | 🔧 fixed |
| [recursion_sequence_minus_100.cpp](exercises/recursion_sequence_minus_100.cpp) | recursive sequence a1=2, an=a(n-1)-100 |  |
| [recursion_sequence_square_minus_100.cpp](exercises/recursion_sequence_square_minus_100.cpp) | recursive sequence an = a(n-1)^2 - 100 | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
