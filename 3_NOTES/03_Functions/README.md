# 03_Functions - Functions - prototypes, parameters, overloading, recursion, lambdas

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/05_numbers.cpp](../../2_BUILDING_BLOCKS/05_numbers.cpp)

```cpp
int dodaj(int a, int b);                 // prototype (declaration) above main
int dodaj(int a, int b)                  // definition
{
    return a + b;
}
void f(int x)            // by value - works on a COPY (use it for int, double, string)
void f(int &x)           // by reference - changes the caller's variable ("returns" values)
void f(int *p)           // by pointer - call with f(&x), use *p
void f(int tab[], int n) // arrays always need the number of elements passed too
void linia(char c = '-', int n = 20);   // default arguments (in the prototype)
long long silnia(int n)                  // recursion needs a base case
{
    if (n == 0)
    {
        return 1;
    }
    return n * silnia(n - 1);
}
auto kw = [](int x) { return x * x; };  // lambda - only to recognise it; write a normal function
```
Overloading = same name, different parameter list (number or types). Return type alone is not enough.

## Files

| File | What it shows | |
|---|---|---|
| [01_function_basics.cpp](01_function_basics.cpp) | function basics - prototype vs definition, return values, void, parameters, default arguments, passing arrays, returning two values through references | ⭐ 🆕 added |
| [02_pass_by_value_reference_pointer.cpp](02_pass_by_value_reference_pointer.cpp) | the same sphere calculation written 3 ways: by value, by reference (output params), by pointer | ⭐ |
| [03_function_overloading.cpp](03_function_overloading.cpp) | overloading: wypisz(int), wypisz(double), wypisz(string), wypisz(int,int) |  |
| [04_inline_functions.cpp](04_inline_functions.cpp) | inline functions (what the keyword means) |  |
| [05_lambda_as_local_function.cpp](05_lambda_as_local_function.cpp) | normal function vs the same thing as a lambda |  |
| [06_recursion_factorial.cpp](06_recursion_factorial.cpp) | recursive factorial with base case |  |
| [07_factorial_iterative.cpp](07_factorial_iterative.cpp) | factorial with a loop (iterative) |  |
| [08_recursion_print_1_to_n.cpp](08_recursion_print_1_to_n.cpp) | recursion: print 1..n (recursive call BEFORE printing) |  |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [overloading_powieksz.cpp](exercises/overloading_powieksz.cpp) | overloads powieksz(int), (int,int), (double) |  |
| [recursion_sequence_2x_minus_4.cpp](exercises/recursion_sequence_2x_minus_4.cpp) | recursive sequence a1 = 1, an = 2(a(n-1) - 1) - 4 | 🔧 fixed |
| [recursion_sequence_minus_100.cpp](exercises/recursion_sequence_minus_100.cpp) | recursive sequence a1=2, an=a(n-1)-100 |  |
| [recursion_sequence_square_minus_100.cpp](exercises/recursion_sequence_square_minus_100.cpp) | recursive sequence an = a(n-1)^2 - 100 | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
