# 09_Pointers_References - Pointers, references, new/delete, smart pointers

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/03_arrays.cpp](../../2_BUILDING_BLOCKS/03_arrays.cpp)

```cpp
int x = 5;
int *p = &x;     // p holds the ADDRESS of x       *p = 7;   // changes x (dereference)
int &r = x;      // r is another NAME for x        r = 9;    // changes x
int *q = nullptr;                    // points nowhere - check before using
int *one = new int(5);   delete one;          // single object
int *arr = new int[n];   delete[] arr;        // array -> delete[]
p++  *(p + i) == p[i]                         // pointer arithmetic on arrays
const int *a;    // can't change the VALUE        int *const b = &x;  // can't change the ADDRESS
obj->field  ==  (*obj).field                  // member access through a pointer
unique_ptr<T> u = make_unique<T>(...);        // deletes itself (#include <memory>)
```

## Files

| File | What it shows | |
|---|---|---|
| [01_overview_pointers.cpp](01_overview_pointers.cpp) | basics, dereference, pointer arithmetic, pointer to array, pointer to pointer, nullptr, function pointer, new/delete, const pointer vs pointer to const, array of pointers | ⭐ 🔧 fixed |
| [02_address_operator_sizeof.cpp](02_address_operator_sizeof.cpp) | &amp; address-of and sizeof for int/double/long/float (Polish comments) |  |
| [03_new_delete.cpp](03_new_delete.cpp) | new int, new double, new int[5], delete / delete[], set to nullptr after delete | ⭐ |
| [04_new_delete_grades.cpp](04_new_delete_grades.cpp) | 4 dynamically allocated doubles, read grades, average |  |
| [05_references_to_objects.cpp](05_references_to_objects.cpp) | prototypes before main, return Pracownik&amp;, const Pracownik&amp; parameter |  |
| [06_references_and_smart_pointers.cpp](06_references_and_smart_pointers.cpp) | references (alias), reference vs pointer side by side, swap 3 ways, const reference, dangling pointer, smart pointers (unique_ptr, shared_ptr) | 🆕 added |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [object_on_heap_pointer_functions.cpp](exercises/object_on_heap_pointer_functions.cpp) | object created with new, passed by pointer to functions | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
