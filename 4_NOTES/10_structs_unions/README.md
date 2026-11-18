# 10_structs_unions - struct and union

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [3_BUILDING_BLOCKS/08_classes.cpp](../../3_BUILDING_BLOCKS/08_classes.cpp) · [3_BUILDING_BLOCKS/09_files.cpp](../../3_BUILDING_BLOCKS/09_files.cpp)

```cpp
struct Osoba
{
    string imie;
    int wiek;
};
Osoba o = {"Ala", 17};     o.imie      Osoba *wsk = &o;   wsk->wiek
Osoba ludzie[3];           Osoba *dyn = new Osoba[n];   delete[] dyn;
void wypisz(Osoba o);      // pass a struct by value (a copy) - use & only to change it
union Ocena { int calkowita; double rzeczywista; };   // members share ONE memory slot
```
`struct` = everything **public** by default, `class` = **private** by default - otherwise the same.
`union` = all members share ONE memory slot, so only the last one written is valid; size = biggest member.

## Files

| File | What it shows | |
|---|---|---|
| [01_struct_basics.cpp](01_struct_basics.cpp) | struct with method, init with {}, dot / -&gt; access, array of structs, struct as parameter, return a struct | ⭐ 🔧 fixed |
| [02_struct_vs_class.cpp](02_struct_vs_class.cpp) | struct (public by default) vs class (private), constructor in a struct, method in a struct, struct with an array of structs | ⭐ |
| [03_unions.cpp](03_unions.cpp) | union basics: shared memory, overwriting, sizeof union vs struct |  |
| [04_union_grade.cpp](04_union_grade.cpp) | union Ocena {int; double} - writing one member overwrites the other | 🔧 fixed |
| [05_dynamic_array_of_structs.cpp](05_dynamic_array_of_structs.cpp) | new Struct[n] with n from the user, fill, print with a function, delete[] |  |
| [06_weighted_average_structs.cpp](06_weighted_average_structs.cpp) | weighted average; dynamic array of structs passed to functions |  |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
