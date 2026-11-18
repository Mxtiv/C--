# 11_Classes_OOP - Classes - encapsulation, constructors, destructor, static, friend, operators

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/08_classes.cpp](../../2_BUILDING_BLOCKS/08_classes.cpp)

Best single file to learn from: **02_class_complete_example.cpp**.
```cpp
class Prostokat
{
private:                          // only methods of this class can use these
    double szerokosc;
    double wysokosc;
    static int licznik;           // ONE shared copy for ALL objects

public:
    Prostokat()                   // default constructor
    {
        szerokosc = 1;
        wysokosc = 1;
        licznik++;
    }

    Prostokat(double nowaSzerokosc, double nowaWysokosc)   // constructor with parameters
    {
        szerokosc = nowaSzerokosc;   // assign in the body, no ": pole(x)" list
        wysokosc = nowaWysokosc;
        licznik++;
    }

    ~Prostokat()                  // destructor: no params, runs automatically
    {
        licznik--;
    }

    double getSzerokosc()         // getter
    {
        return szerokosc;
    }

    void setSzerokosc(double nowaSzerokosc)   // setter with validation
    {
        if (nowaSzerokosc > 0)
        {
            szerokosc = nowaSzerokosc;
        }
    }

    static int getLicznik()       // called as Prostokat::getLicznik()
    {
        return licznik;
    }
};

int Prostokat::licznik = 0;       // static field defined OUTSIDE the class
```
Only to **recognise** (each has its own file below):
```cpp
Prostokat(double s, double w) : szerokosc(s), wysokosc(w) { }   // initializer list (03, 04)
Prostokat(const Prostokat &wzor)  { ... }                       // copy constructor (05, 06)
friend double odleglosc(Punkt p1, Punkt p2);                    // friend function (08, 11)
friend class Kolo;                                              // friend class (10)
Ulamek operator+(Ulamek drugi)  { ... }                         // operator overloading (14)
```
The copy constructor runs for `Prostokat p2 = p1;`, `Prostokat p3(p1);`, when you pass an object **by value** and when a function **returns** one by value.

## Files

| File | What it shows | |
|---|---|---|
| [01_encapsulation_private_getters_setters.cpp](01_encapsulation_private_getters_setters.cpp) | private fields, public setter, getters (by value and through &amp; params); commented lines show what is NOT allowed | ⭐ |
| [02_class_complete_example.cpp](02_class_complete_example.cpp) | ALL-IN-ONE: private fields, default + parameter ctor, destructor, getters, setters with validation, static counter + static getter | ⭐ |
| [03_constructors_initializer_list.cpp](03_constructors_initializer_list.cpp) | default / parameter constructor; the same constructor with body assignment vs initializer list `: pole(x)` |  |
| [04_initializer_list_const_member.cpp](04_initializer_list_const_member.cpp) | a const field MUST be set in the initializer list; constructor defined outside the class |  |
| [05_copy_constructor_minimal.cpp](05_copy_constructor_minimal.cpp) | minimal copy constructor Prostokat(const Prostokat &amp;wzor) |  |
| [06_copy_constructor_when_called.cpp](06_copy_constructor_when_called.cpp) | methods defined OUTSIDE the class (Prostokat::), the 4 cases when the copy constructor runs | ⭐ |
| [07_destructor_object_lifetime.cpp](07_destructor_object_lifetime.cpp) | when the destructor runs: end of block {}, delete, end of function | ⭐ |
| [08_delegating_copy_static_friend.cpp](08_delegating_copy_static_friend.cpp) | Ksiazka: copy ctor, static counter (int Ksiazka::licznik = 0), friend function; delegating ctor in a comment | ⭐ |
| [09_point_class_static_method.cpp](09_point_class_static_method.cpp) | Punkt: reflect, move, point symmetry, distance to a line, static method Punkt::odleglosc |  |
| [10_friend_classes.cpp](10_friend_classes.cpp) | friend class: Kolo and Kula read the private radius of Promien |  |
| [11_fraction_friend_functions.cpp](11_fraction_friend_functions.cpp) | class Ulamek: 2 ctors, private method (NWD reduce), friend functions dodaj/pomnoz, methods defined outside (was misfiled under PESEL) |  |
| [12_static_member_struct_via_pointer.cpp](12_static_member_struct_via_pointer.cpp) | static field of a struct type; using an object through a pointer with -&gt; |  |
| [13_composition_library_books.cpp](13_composition_library_books.cpp) | composition (not a singleton): Biblioteka holds a Ksiazka* array + count, new in dodaj, delete in the destructor |  |
| [14_operator_overloading.cpp](14_operator_overloading.cpp) | operator overloading (przeciazanie operatorow) on Ulamek: + and == as methods, &lt;&lt; as a friend | 🆕 added |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [encapsulation_setter_getter_ref.cpp](exercises/encapsulation_setter_getter_ref.cpp) | private PESEL (string) + setter with length check + getter by value / by reference | 🔧 fixed |
| [fraction_setter_validation.cpp](exercises/fraction_setter_validation.cpp) | setter with validation returning bool + do-while retry, overloaded getters (by ref / by value) |  |
| [point_static_counter_friend.cpp](exercises/point_static_counter_friend.cpp) | static counter (copy ctor counts too), friend distance function |  |
| [test_egg_code.cpp](exercises/test_egg_code.cpp) | test: decode an egg code (kod jaja), e.g. 1PL12345678 or 1-PL-12345678 - digit 0..3 = type of farming, 2 letters = country, rest = producer number; private helper methods | 🔧 fixed |
| [test_water_dispenser_interactive.cpp](exercises/test_water_dispenser_interactive.cpp) | test: water dispenser - ctor, setters, int &amp;kubek output param, static counter + static getter, do-while "pour more?" | 🔧 fixed |
| [uml_motor_teacher_solution.cpp](exercises/uml_motor_teacher_solution.cpp) | teacher's model solution of the UML "Motor" task (public fields exactly as the diagram says) | ⭐ |
| [uml_motor_friend_compare.cpp](exercises/uml_motor_friend_compare.cpp) | Motor + friend function porownaj(Motor, Motor) that returns the winning object | 🔧 fixed |
| [uml_pizza_machine.cpp](exercises/uml_pizza_machine.cpp) | UML pizza machine: constructor with prices, setters, calculation methods (price, calories, vege) | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
