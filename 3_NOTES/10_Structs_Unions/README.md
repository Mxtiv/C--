# 10_Structs_Unions - struct and union

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/08_classes.cpp](../../2_BUILDING_BLOCKS/08_classes.cpp) · [2_BUILDING_BLOCKS/09_files.cpp](../../2_BUILDING_BLOCKS/09_files.cpp)

```cpp
struct Person { string name; int age = 0; void show() { cout << name; } };
Person p = {"Ala", 17};    p.name    Person *pp = &p;  pp->age
Person people[3];          Person *dyn = new Person[n];  delete[] dyn;
void print(const Person &p);   // pass structs by const reference
```
`struct` = everything **public** by default, `class` = **private** by default - otherwise the same.
`union` = all members share ONE memory slot, so only the last one written is valid.

## Files

| File | What it shows | |
|---|---|---|
| [01_struct_basics.cpp](01_struct_basics.cpp) | struct with method, aggregate init {}, dot / -&gt; access, array of structs, pass by const&amp;, return a struct | ⭐ 🔧 fixed |
| [02_struct_vs_class.cpp](02_struct_vs_class.cpp) | struct (public by default) vs class (private), ctor in struct, default member values, nested struct with array | ⭐ |
| [03_unions.cpp](03_unions.cpp) | union, anonymous union inside struct, sizeof, strcpy |  |
| [04_union_grade.cpp](04_union_grade.cpp) | union Ocena {short; float} - writing one member overwrites the other | 🔧 fixed |
| [05_dynamic_array_of_structs.cpp](05_dynamic_array_of_structs.cpp) | new Struct[n], const&amp; param, fixed &lt;&lt; setprecision(2) |  |
| [06_weighted_average_structs.cpp](06_weighted_average_structs.cpp) | weighted average; dynamic struct array passed as pointer BY REFERENCE (srednia *&amp;) |  |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
