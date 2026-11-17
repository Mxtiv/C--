# 11_Classes_OOP - Classes - encapsulation, constructors, destructor, static, friend, operators

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/08_classes.cpp](../../2_BUILDING_BLOCKS/08_classes.cpp)

Best single file to learn from: **02_class_complete_example.cpp**.
```cpp
class Box {
private:                         // only methods of this class can use these
    int w, h;
    static int count;            // one shared copy for ALL objects
public:
    Box() : Box(1, 1) {}                         // delegating constructor
    Box(int w, int h) : w(w), h(h) { count++; }  // initializer list
    Box(const Box &o) : w(o.w), h(o.h) { count++; }  // copy constructor
    ~Box() { count--; }                          // destructor (no params, runs automatically)
    int getW() const { return w; }               // getter; const = does not modify the object
    void setW(int v) { if (v > 0) w = v; }       // setter with validation
    static int getCount() { return count; }
    friend void show(const Box &b);              // friend function may read private fields
    Box operator+(const Box &o) const;           // operator overloading
};
int Box::count = 0;                              // static member definition OUTSIDE the class
int Box::area() const { return w * h; }          // method defined outside (if declared inside)
```
The copy constructor runs for `Box b2 = b1;`, `Box b3(b1);`, when you pass an object **by value** and when a function **returns** one by value.

## Files

| File | What it shows | |
|---|---|---|
| [01_encapsulation_private_getters_setters.cpp](01_encapsulation_private_getters_setters.cpp) | private fields, public setter, getter through reference params; commented lines show what is NOT allowed | ⭐ |
| [02_class_complete_example.cpp](02_class_complete_example.cpp) | ALL-IN-ONE: private fields, static counter, default ctor, delegating ctor, copy ctor, destructor, const getters, setters, static getter | ⭐ |
| [03_constructors_initializer_list.cpp](03_constructors_initializer_list.cpp) | default / parameter / copy constructor written with initializer lists; brace-init objects |  |
| [04_initializer_list_const_member.cpp](04_initializer_list_const_member.cpp) | const member MUST be set in the initializer list; constructors defined outside the class |  |
| [05_copy_constructor_minimal.cpp](05_copy_constructor_minimal.cpp) | minimal copy constructor Prostokat(const Prostokat&amp;) |  |
| [06_copy_constructor_when_called.cpp](06_copy_constructor_when_called.cpp) | methods defined OUTSIDE the class (Prostokat::), implicit vs explicit copy, copies when passing/returning by value | ⭐ |
| [07_destructor_object_lifetime.cpp](07_destructor_object_lifetime.cpp) | when the destructor runs: end of block {}, delete, end of function | ⭐ |
| [08_delegating_copy_static_friend.cpp](08_delegating_copy_static_friend.cpp) | delegating ctor, initializer list, copy ctor, static counter (int Ksiazka::x = 0), friend function | ⭐ |
| [09_point_class_static_method.cpp](09_point_class_static_method.cpp) | Point: 3 ctors, reflect, move, distance to a line, point symmetry, const getters, static method |  |
| [10_friend_classes.cpp](10_friend_classes.cpp) | friend class: Kolo and Kula read private radius of Promien; M_PI |  |
| [11_fraction_friend_functions.cpp](11_fraction_friend_functions.cpp) | class Ulamek: 2 ctors, private method (GCD reduce), friend functions dodaj/pomnoz, methods defined outside (was misfiled under PESEL) |  |
| [12_static_member_struct_via_pointer.cpp](12_static_member_struct_via_pointer.cpp) | static member of a struct type; access through a pointer with -&gt; |  |
| [13_composition_library_books.cpp](13_composition_library_books.cpp) | composition (not a singleton): Library holds Book* array, new/delete in destructor, const getters |  |
| [14_operator_overloading.cpp](14_operator_overloading.cpp) | operator overloading (przeciazanie operatorow) on a Fraction class - + - * as members, == and &lt; , unary -, +=, ++ (pre/post), &lt;&lt; and &gt;&gt; as friends | 🆕 added |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [encapsulation_setter_getter_ref.cpp](exercises/encapsulation_setter_getter_ref.cpp) | private pesel + setter + getter by reference | 🔧 fixed |
| [fraction_setter_validation.cpp](exercises/fraction_setter_validation.cpp) | setter with validation + exit(-1), overloaded getters (by ref / by value) |  |
| [point_static_counter_friend.cpp](exercises/point_static_counter_friend.cpp) | static counter, delegating ctor, copy ctor, friend distance function |  |
| [test_egg_code.cpp](exercises/test_egg_code.cpp) | test: decode an egg code (kod jaja), e.g. 1PL12345678 or 1-PL-12345678 digit 0..3 = type of farming, 2 letters = country, rest = producer number | 🔧 fixed |
| [test_water_dispenser_interactive.cpp](exercises/test_water_dispenser_interactive.cpp) | interactive version of the dispenser | 🔧 fixed |
| [test_water_dispenser_static.cpp](exercises/test_water_dispenser_static.cpp) | test: ctor, int&amp; output param, static counter + static getter, ternary display |  |
| [uml_motor_final_compare.cpp](exercises/uml_motor_final_compare.cpp) | full interactive Motor: objects passed by reference, function returns an object, min() |  |
| [uml_motor_friend_compare.cpp](exercises/uml_motor_friend_compare.cpp) | Motor + friend function porownaj(Motor, Motor) | 🔧 fixed |
| [uml_motor_teacher_solution.cpp](exercises/uml_motor_teacher_solution.cpp) | teacher's model solution of the UML "Motor" task |  |
| [uml_pizza_machine.cpp](exercises/uml_pizza_machine.cpp) | UML pizza machine: init list, this-&gt; setters, calculation methods | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
