# 19_Multi_File_Projects - Multi-file projects - .h + .cpp

[⬅ notes index](../README.md) · [main index](../../README.md)

The pattern (see **01_clean_example/**):
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

### 01_clean_example/ - build inside this folder: `g++ *.cpp -o program.exe`

| File | What it shows | |
|---|---|---|
| [Prostokat.cpp](01_clean_example/Prostokat.cpp) | SOURCE (.cpp): the DEFINITIONS (Prostokat::pole ...), static field defined once | 🆕 added |
| [Prostokat.h](01_clean_example/Prostokat.h) | the CORRECT way to split a class into .h + .cpp: guard, class with prototypes, static field declaration | 🆕 added |
| [main.cpp](01_clean_example/main.cpp) | main.cpp of a correctly split multi-file program | ⭐ 🆕 added |

### 02_normalizacja_litry/ - build inside this folder: `g++ *.cpp -o program.exe`

| File | What it shows | |
|---|---|---|
| [main.cpp](02_normalizacja_litry/main.cpp) | multi-file: main.cpp + operacje.h + operacje.cpp |  |
| [operacje.cpp](02_normalizacja_litry/operacje.cpp) | definitions: litres into tanks / baths / gallons / litres, struct filled through &amp; | 🔧 fixed |
| [operacje.h](02_normalizacja_litry/operacje.h) | include guard, struct + prototypes |  |

### 03_litry_namespace_struct/ - build inside this folder: `g++ *.cpp -o program.exe`

| File | What it shows | |
|---|---|---|
| [litry.cpp](03_litry_namespace_struct/litry.cpp) | definitions: greedy conversion of litres into tanks / baths / gallons / litres | 🔧 fixed |
| [litry.h](03_litry_namespace_struct/litry.h) | header: namespace with constants, struct, function prototype | 🔧 fixed |
| [main.cpp](03_litry_namespace_struct/main.cpp) | uses the namespace constants (pojemnosci::WANNA) and the struct |  |

### 04_spis_ludnosci/ - build inside this folder: `g++ *.cpp -o program.exe`

| File | What it shows | |
|---|---|---|
| [main.cpp](04_spis_ludnosci/main.cpp) | census: struct array via new, search by name/age, do-while menu, switch with random goodbye |  |
| [sprawdzian2.cpp](04_spis_ludnosci/sprawdzian2.cpp) | definitions | 🔧 fixed |
| [sprawdzian2.h](04_spis_ludnosci/sprawdzian2.h) | header: struct Obywatel + prototypes of the census functions | 🔧 fixed |

### 05_osoby_dynamic_struct_array/ - build inside this folder: `g++ *.cpp -o program.exe`

| File | What it shows | |
|---|---|---|
| [main.cpp](05_osoby_dynamic_struct_array/main.cpp) | dynamic array of structs created by a function from another file | 🔧 fixed |
| [sprawdzian.cpp](05_osoby_dynamic_struct_array/sprawdzian.cpp) | definitions | 🔧 fixed |
| [sprawdzian.h](05_osoby_dynamic_struct_array/sprawdzian.h) | header: struct Osoba + prototypes | 🔧 fixed |

### 06_struktura_programu/ - build inside this folder: `g++ *.cpp -o program.exe`

| File | What it shows | |
|---|---|---|
| [main.cpp](06_struktura_programu/main.cpp) | main using functions from operacje.h |  |
| [operacje.cpp](06_struktura_programu/operacje.cpp) | definitions - this file was EMPTY in your repo, so the project could not link | 🆕 added |
| [operacje.h](06_struktura_programu/operacje.h) | include guard + prototypes only |  |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
