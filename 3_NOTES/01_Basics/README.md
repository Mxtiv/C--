# 01_Basics - Basics - program structure, types, I/O, operators, conditions, conversions, random, enum

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/01_input_output.cpp](../../2_BUILDING_BLOCKS/01_input_output.cpp) · [2_BUILDING_BLOCKS/02_random.cpp](../../2_BUILDING_BLOCKS/02_random.cpp)

```cpp
#include <iostream>            // cout, cin
using namespace std;
int main() { cout << "Hi" << endl; return 0; }

int i = 5;  double d = 2.5;  char c = 'A';  bool b = true;  string s = "text";
const int MAX = 10;            // constant           auto x = 3.14;   // type deduced
cin >> i;                      // one word/number    getline(cin, s);  // whole line
cin.ignore(1000, '\n');        // after cin >> and BEFORE getline
cout << fixed << setprecision(2) << d;   // #include <iomanip>
7 / 2 == 3      7 % 2 == 1     7 / 2.0 == 3.5     (double)a / b
if (x > 0) {...} else if (x == 0) {...} else {...}
switch (n) { case 1: ...; break; default: ...; }
cond ? valueIfTrue : valueIfFalse
stoi("42")  stod("3.5")  to_string(42)  ch - '0'  (digit char -> int)
srand(time(0));  rand() % (max - min + 1) + min      // ONCE srand, at the start of main
```

## Files

| File | What it shows | |
|---|---|---|
| [01_hello_world_structure.cpp](01_hello_world_structure.cpp) | structure of every C++ program | 🆕 added |
| [02_variables_types_constants.cpp](02_variables_types_constants.cpp) | variables, data types, constants, sizeof, limits, auto | 🆕 added |
| [03_input_output_iomanip.cpp](03_input_output_iomanip.cpp) | reading input (cin, getline) and formatting output (iomanip) | 🆕 added |
| [04_operators.cpp](04_operators.cpp) | operators - arithmetic, integer division, modulo, increment, compound assignment, comparison, logical, ternary, precedence | 🆕 added |
| [05_if_else_switch_ternary.cpp](05_if_else_switch_ternary.cpp) | if / else if / else, nested if, switch (with fall-through), ternary | 🆕 added |
| [06_type_conversion_cast_stoi_to_string.cpp](06_type_conversion_cast_stoi_to_string.cpp) | type conversions - implicit, static_cast, C-style cast, string &lt;-&gt; number (stoi, stod, to_string), char &lt;-&gt; int | 🆕 added |
| [07_c_string_to_number_atoi_atof_strtol.cpp](07_c_string_to_number_atoi_atof_strtol.cpp) | C-string -&gt; number: atof, strtof, atoi, atol, strtol |  |
| [08_random_numbers.cpp](08_random_numbers.cpp) | random numbers - rand/srand (exam style) and &lt;random&gt; (modern) | 🆕 added |
| [09_enum_namespace_scope.cpp](09_enum_namespace_scope.cpp) | enum, enum class, namespace, using, typedef/using alias, static local | 🆕 added |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
