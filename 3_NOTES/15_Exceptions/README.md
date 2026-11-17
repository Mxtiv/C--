# 15_Exceptions - Exceptions - try / throw / catch, std exceptions, custom classes

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/10_exceptions.cpp](../../2_BUILDING_BLOCKS/10_exceptions.cpp)

```cpp
try {
    if (b == 0) throw runtime_error("division by zero");
    if (x < 0) throw x;                      // you can throw any type
}
catch (int v) { }                            // catch picks by the TYPE thrown
catch (const runtime_error &e) { cout << e.what(); }
catch (const exception &e) { }               // base of all std exceptions - put it LAST
catch (...) { }                              // anything else
class MyError : public exception {
public: const char *what() const noexcept override { return "message"; } };
class MyLogic : public logic_error { public: MyLogic(const string &m) : logic_error(m) {} };
```
Thrown by the library: `stoi` → `invalid_argument` / `out_of_range`, `.at()` → `out_of_range`, `new` → `bad_alloc`. Hierarchy: see `exception_hierarchy.txt`.

## Files

| File | What it shows | |
|---|---|---|
| [01_custom_exception_what.cpp](01_custom_exception_what.cpp) | std::exception definition (comment), override what() noexcept, catch(const exception&amp;) | ⭐ |
| [02_throw_const_char_and_int.cpp](02_throw_const_char_and_int.cpp) | throw "text" -&gt; catch(const char*), throw 18 -&gt; catch(int) |  |
| [03_catch_by_type_catch_all.cpp](03_catch_by_type_catch_all.cpp) | catch(double)/(int)/(float)/(...) - catch picks by the TYPE thrown | ⭐ 🔧 fixed |
| [04_divide_by_zero.cpp](04_divide_by_zero.cpp) | divide by zero with a custom exception class |  |
| [05_int_logic_error_custom.cpp](05_int_logic_error_custom.cpp) | throw int / logic_error("...") / custom class (exercise text included) |  |
| [06_standard_library_exceptions.cpp](06_standard_library_exceptions.cpp) | exceptions thrown BY THE STANDARD LIBRARY and how to catch them - stoi (invalid_argument, out_of_range), vector::at / string::at (out_of_range), new (bad_alloc), catch order, rethrow, function that validates and throws | 🆕 added |
| [exception_hierarchy.txt](exception_hierarchy.txt) | reference text file |  |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [task1_basketball_height.cpp](exercises/task1_basketball_height.cpp) | throw int/double/float/const char* + catch(...) |  |
| [task3_negative_or_fraction.cpp](exercises/task3_negative_or_fraction.cpp) | class derived from logic_error with a message ctor | 🔧 fixed |
| [task4_two_digit_number.cpp](exercises/task4_two_digit_number.cpp) | three ways: int, logic_error-derived, exception-derived |  |
| [test_groupA_even_positive.cpp](exercises/test_groupA_even_positive.cpp) | test group A: read a positive EVEN number; each kind of wrong input is reported with a different exception mechanism | 🔧 fixed |
| [test_groupB_uppercase_letter.cpp](exercises/test_groupB_uppercase_letter.cpp) | test group B: cctype + exception / runtime_error / derived class |  |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
