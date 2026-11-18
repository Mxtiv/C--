# 19_multi_file_projects - Multi-file projects - .h + .cpp

[⬅ notes index](../README.md) · [main index](../../README.md)

The pattern (see **01_class_split_into_h_and_cpp/**):
* **`X.h`**: include guard + declarations only (class, struct, prototypes, constants).
* **`X.cpp`**: `#include "X.h"` + the definitions (`double Prostokat::pole() { ... }`, static members).
* **`main.cpp`**: `#include "X.h"`. **Never `#include` a `.cpp` file.**
* Build every `.cpp` together: `g++ main.cpp X.cpp -o program.exe`

```cpp
// Prostokat.h
#ifndef PROSTOKAT_H
#define PROSTOKAT_H
class Prostokat
{
private:
    double a;
    double b;
    static int liczbaProstokatow;     // deklaracja
public:
    Prostokat(double bokA, double bokB);
    double pole();
};
#endif

// Prostokat.cpp
#include "Prostokat.h"
int Prostokat::liczbaProstokatow = 0;     // definicja static - raz, w .cpp
Prostokat::Prostokat(double bokA, double bokB)
{
    a = bokA;
    b = bokB;
    liczbaProstokatow++;
}
double Prostokat::pole()
{
    return a * b;
}
```
The headers here use `using namespace std;` like every other file in the toolbox (big projects avoid it in `.h` files - at the exam it's fine).

Every project folder here builds with `g++ *.cpp -o program.exe` run inside that folder.

## Files

### 01_class_split_into_h_and_cpp/ - build inside this folder: `g++ *.cpp -o program.exe`

| File | What it shows | |
|---|---|---|
| [Prostokat.cpp](01_class_split_into_h_and_cpp/Prostokat.cpp) | SOURCE (.cpp): the DEFINITIONS (Prostokat::pole ...), static field defined once | 🆕 added |
| [Prostokat.h](01_class_split_into_h_and_cpp/Prostokat.h) | the CORRECT way to split a class into .h + .cpp: guard, class with prototypes, static field declaration | 🆕 added |
| [main.cpp](01_class_split_into_h_and_cpp/main.cpp) | main.cpp of a correctly split multi-file program | ⭐ 🆕 added |

### 02_litres_normalization/ - build inside this folder: `g++ *.cpp -o program.exe`

| File | What it shows | |
|---|---|---|
| [main.cpp](02_litres_normalization/main.cpp) | multi-file: main.cpp + operations.h + operations.cpp |  |
| [operations.cpp](02_litres_normalization/operations.cpp) | definitions: litres into tanks / baths / gallons / litres, struct filled through &amp; | 🔧 fixed |
| [operations.h](02_litres_normalization/operations.h) | include guard, struct + prototypes |  |

### 03_litres_namespace_struct/ - build inside this folder: `g++ *.cpp -o program.exe`

| File | What it shows | |
|---|---|---|
| [litres.cpp](03_litres_namespace_struct/litres.cpp) | definitions: greedy conversion of litres into tanks / baths / gallons / litres | 🔧 fixed |
| [litres.h](03_litres_namespace_struct/litres.h) | header: namespace with constants, struct, function prototype | 🔧 fixed |
| [main.cpp](03_litres_namespace_struct/main.cpp) | uses the namespace constants (pojemnosci::WANNA) and the struct |  |

### 04_census_struct_array/ - build inside this folder: `g++ *.cpp -o program.exe`

| File | What it shows | |
|---|---|---|
| [main.cpp](04_census_struct_array/main.cpp) | census: struct array via new, search by name/age, do-while menu, switch with random goodbye |  |
| [census.cpp](04_census_struct_array/census.cpp) | definitions | 🔧 fixed |
| [census.h](04_census_struct_array/census.h) | header: struct Obywatel + prototypes of the census functions | 🔧 fixed |

### 05_people_dynamic_struct_array/ - build inside this folder: `g++ *.cpp -o program.exe`

| File | What it shows | |
|---|---|---|
| [main.cpp](05_people_dynamic_struct_array/main.cpp) | dynamic array of structs created by a function from another file | 🔧 fixed |
| [people.cpp](05_people_dynamic_struct_array/people.cpp) | definitions | 🔧 fixed |
| [people.h](05_people_dynamic_struct_array/people.h) | header: struct Osoba + prototypes | 🔧 fixed |

### 06_program_structure/ - build inside this folder: `g++ *.cpp -o program.exe`

| File | What it shows | |
|---|---|---|
| [main.cpp](06_program_structure/main.cpp) | main using functions from operations.h |  |
| [operations.cpp](06_program_structure/operations.cpp) | definitions - this file was EMPTY in your repo, so the project could not link | 🆕 added |
| [operations.h](06_program_structure/operations.h) | include guard + prototypes only |  |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
