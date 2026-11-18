# 09_pointers_references - Pointers, references, new/delete, smart pointers

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [3_BUILDING_BLOCKS/03_arrays.cpp](../../3_BUILDING_BLOCKS/03_arrays.cpp)

```cpp
int x = 5;
int *p = &x;     // p holds the ADDRESS of x       *p = 7;   // changes x (dereference)
int &r = x;      // r is another NAME for x        r = 9;    // changes x
int *q = nullptr;                    // points nowhere - check before using
int *one = new int;      delete one;          // single value
int *tab = new int[n];   delete[] tab;        // array -> delete[]
tab = nullptr;                                // after delete, so it doesn't point to freed memory
p++   *(p + i) == p[i]                        // pointer arithmetic on arrays
void f(int *p)  -> f(&x);      void f(int &r)  -> f(x);
obiekt->pole  ==  (*obiekt).pole              // member access through a pointer
unique_ptr<int> u = make_unique<int>(5);      // only to recognise: deletes itself (#include <memory>)
```

## Files

| File | What it shows | |
|---|---|---|
| [01_pointers_overview.cpp](01_pointers_overview.cpp) | basics, dereference, pointer arithmetic, pointer to array, pointer to pointer, nullptr, pointer parameter, new/delete | ⭐ |
| [02_address_operator_sizeof.cpp](02_address_operator_sizeof.cpp) | &amp; address-of and sizeof for int / double / char / bool (Polish comments) |  |
| [03_new_delete.cpp](03_new_delete.cpp) | new int, new double, new int[n], delete / delete[], set to nullptr after delete | ⭐ |
| [04_new_delete_grades.cpp](04_new_delete_grades.cpp) | 4 dynamically allocated doubles, read grades, average |  |
| [05_references_to_objects.cpp](05_references_to_objects.cpp) | prototypes before main, Pracownik&amp; parameter fills the caller's object |  |
| [06_references_and_smart_pointers.cpp](06_references_and_smart_pointers.cpp) | references (alias), reference vs pointer, swap 3 ways, dangling pointer, tiny unique_ptr example | 🆕 added |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [object_on_heap_pointer_functions.cpp](exercises/object_on_heap_pointer_functions.cpp) | object created with new, passed by pointer to functions (-&gt;) | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
