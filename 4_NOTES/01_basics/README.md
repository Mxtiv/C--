# 01_basics - Basics - program structure, types, I/O, operators, conditions, conversions, random, enum

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [3_BUILDING_BLOCKS/01_input_output.cpp](../../3_BUILDING_BLOCKS/01_input_output.cpp) · [3_BUILDING_BLOCKS/02_random.cpp](../../3_BUILDING_BLOCKS/02_random.cpp)

```cpp
#include <iostream>            // cout, cin
using namespace std;
int main()
{
    cout << "Hi" << endl;
    return 0;
}

int i = 5;  double d = 2.5;  char c = 'A';  bool b = true;  string s = "text";
const int MAX = 10;            // constant           long long big = 9000000000;  // big results
cin >> i;                      // one word/number    getline(cin, s);  // whole line
cin.ignore();                  // after cin >> and BEFORE getline
do { cin >> i; } while (i < 1 || i > 10);   // ask again until the value is OK
7 / 2 == 3      7 % 2 == 1     7 / 2.0 == 3.5     (double)a / b
if (x > 0) {...} else if (x == 0) {...} else {...}
switch (n) { case 1: ...; break; default: ...; break; }
stoi("42")  stod("3.5")  to_string(42)  ch - '0'  (digit char -> int)
srand(time(0));  rand() % (max - min + 1) + min      // ONCE srand, at the start of main
// You may SEE (not needed in exam code): cond ? a : b   fixed << setprecision(2)   static_cast<double>(x)
```

## Files

| File | What it shows | |
|---|---|---|
| [01_hello_world_structure.cpp](01_hello_world_structure.cpp) | structure of every C++ program | 🆕 added |
| [02_variables_types_constants.cpp](02_variables_types_constants.cpp) | variables, data types, constants, sizeof, overflow, scope | 🆕 added |
| [03_input_output_iomanip.cpp](03_input_output_iomanip.cpp) | cin, do-while validation, cin.ignore + getline; iomanip basics (fixed, setprecision, setw) | 🆕 added |
| [04_operators.cpp](04_operators.cpp) | operators - arithmetic, integer division, modulo, increment, compound assignment, comparison, logical, precedence, char arithmetic | 🆕 added |
| [05_if_else_switch_ternary.cpp](05_if_else_switch_ternary.cpp) | if / else if / else, switch (with fall-through), ternary next to the same if/else | 🆕 added |
| [06_type_conversion_cast_stoi_to_string.cpp](06_type_conversion_cast_stoi_to_string.cpp) | type conversions - implicit, (double) cast, string &lt;-&gt; number (stoi, stod, to_string), char &lt;-&gt; int | 🆕 added |
| [07_c_string_to_number_atoi_atof_strtol.cpp](07_c_string_to_number_atoi_atof_strtol.cpp) | C-string -&gt; number: atoi, atof, strtol |  |
| [08_random_numbers.cpp](08_random_numbers.cpp) | random numbers - rand / srand(time(0)), range formula, random array | 🆕 added |
| [09_enum_namespace_scope.cpp](09_enum_namespace_scope.cpp) | enum, enum class, namespace, static local variable | 🆕 added |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
