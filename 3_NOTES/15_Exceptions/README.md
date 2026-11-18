# 15_Exceptions - Exceptions - try / throw / catch, std exceptions, own classes

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/10_exceptions.cpp](../../2_BUILDING_BLOCKS/10_exceptions.cpp)

```cpp
#include <stdexcept>                 // runtime_error, logic_error, invalid_argument, out_of_range

try
{
    if (x < 0)
    {
        throw x;                     // mozna rzucic dowolny typ: int, double, "tekst"...
    }
    if (b == 0)
    {
        throw runtime_error("dzielenie przez zero");
    }
}
catch (int wartosc) { ... }          // catch wybiera po TYPIE rzuconej wartosci
catch (const char* tekst) { ... }    // throw "tekst"
catch (runtime_error &e)             // wyjatki-klasy lapiemy przez referencje &
{
    cout << e.what();                // what() = tekst podany przy throw
}
catch (exception &e) { ... }         // baza wszystkich wyjatkow biblioteki - po szczegolowych
catch (...) { ... }                  // cokolwiek innego - ZAWSZE na koncu

class MojWyjatek : public exception  // wlasna klasa: what() z naglowkiem jak w exception
{
public:
    const char* what() const noexcept
    {
        return "komunikat";
    }
};
```
Rzucane przez bibliotekę: `stoi("abc")` → `invalid_argument`, `tekst.at(100)` → `out_of_range`. Hierarchia: zobacz `exception_hierarchy.txt`.

## Files

| File | What it shows | |
|---|---|---|
| [01_custom_exception_what.cpp](01_custom_exception_what.cpp) | own class derived from exception, redefined what(), catch(exception &amp;e) | ⭐ |
| [02_throw_const_char_and_int.cpp](02_throw_const_char_and_int.cpp) | throw "text" -&gt; catch(const char*), throw 18 -&gt; catch(int) | ⭐ |
| [03_catch_by_type_catch_all.cpp](03_catch_by_type_catch_all.cpp) | catch(double)/(int)/(float)/(...) - catch picks by the TYPE thrown | ⭐ 🔧 fixed |
| [04_divide_by_zero.cpp](04_divide_by_zero.cpp) | function throws runtime_error on division by zero, main catches it |  |
| [05_int_logic_error_custom.cpp](05_int_logic_error_custom.cpp) | throw int / logic_error("...") / simplest own class (plain class with a message field) - exercise text included |  |
| [06_standard_library_exceptions.cpp](06_standard_library_exceptions.cpp) | exceptions thrown BY THE LIBRARY: stoi (invalid_argument), string.at() (out_of_range), catch order | 🆕 added |
| [exception_hierarchy.txt](exception_hierarchy.txt) | the main standard exception classes |  |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [task1_basketball_height.cpp](exercises/task1_basketball_height.cpp) | throw int/double/float/const char* + catch(...) |  |
| [task3_negative_or_fraction.cpp](exercises/task3_negative_or_fraction.cpp) | two ways: runtime_error and logic_error | 🔧 fixed |
| [task4_two_digit_number.cpp](exercises/task4_two_digit_number.cpp) | three ways: int, runtime_error, own class derived from exception |  |
| [test_groupA_even_positive.cpp](exercises/test_groupA_even_positive.cpp) | test group A: read a positive EVEN number; int / exception / runtime_error / class derived from runtime_error | 🔧 fixed |
| [test_groupB_uppercase_letter.cpp](exercises/test_groupB_uppercase_letter.cpp) | test group B: cctype + int / exception / runtime_error / class derived from runtime_error |  |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
