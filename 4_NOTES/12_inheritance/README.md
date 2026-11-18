# 12_inheritance - Inheritance - public / protected / private, constructor order, multiple

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [3_BUILDING_BLOCKS/08_classes.cpp](../../3_BUILDING_BLOCKS/08_classes.cpp)

```cpp
class Pracownik
{
protected:                       // protected = widac w klasach pochodnych, w main nie
    string imie;

public:
    Pracownik(string noweImie)
    {
        imie = noweImie;
    }
};

class Nauczyciel : public Pracownik          // Nauczyciel JEST Pracownikiem
{
private:
    string przedmiot;

public:
    Nauczyciel(string noweImie, string nowyPrzedmiot) : Pracownik(noweImie)   // wywolanie konstruktora BAZY
    {
        przedmiot = nowyPrzedmiot;
    }
};

class Laptop : public Pamiec, public Procesor   // dziedziczenie wielokrotne
{
};
```
**What a base member becomes in the derived class:**

| base member is → | `public` inheritance | `protected` inheritance | `private` inheritance |
|---|---|---|---|
| public | public | protected | private |
| protected | protected | protected | private |
| private | not accessible | not accessible | not accessible |

"protected/private" = usable inside the derived class, **not** from `main` - that's why those tasks need setters/getters.
Construction order: base → derived. Destruction order: derived → base.

## Files

| File | What it shows | |
|---|---|---|
| [01_public_inheritance.cpp](01_public_inheritance.cpp) | public inheritance: main uses inherited public fields; method hiding, `Pracownik::zwrocDane()` | ⭐ |
| [02_protected_inheritance_getters_setters.cpp](02_protected_inheritance_getters_setters.cpp) | protected inheritance -&gt; inherited public members become protected, so you need setters/getters | ⭐ |
| [03_constructor_destructor_order.cpp](03_constructor_destructor_order.cpp) | ctor order base -&gt; derived, dtor order derived -&gt; base, calling the base ctor: `Nauczyciel(...) : Pracownik(a, b)` | ⭐ |
| [04_access_levels_public_protected_private.cpp](04_access_levels_public_protected_private.cpp) | public / protected / private members through protected inheritance; `Bazowa::metoda()` call |  |
| [05_private_inheritance.cpp](05_private_inheritance.cpp) | private inheritance (task text included); access through derived-class methods |  |
| [06_multilevel_inheritance.cpp](06_multilevel_inheritance.cpp) | 3-level chain Pracownik -&gt; Nauczyciel -&gt; Wychowawca, each calls the ctor one level up |  |
| [07_multiple_inheritance_computer.cpp](07_multiple_inheritance_computer.cpp) | MULTIPLE inheritance Laptop : Pamiec, Procesor, Ekran; calling several base ctors | ⭐ |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [derived_field_hides_base_field.cpp](exercises/derived_field_hides_base_field.cpp) | derived class redeclares `cyfra`, hiding the base field (`liczba2.Liczba1::cyfra`) | 🔧 fixed |
| [private_inheritance_private_member.cpp](exercises/private_inheritance_private_member.cpp) | private/protected/public members + PRIVATE inheritance |  |
| [protected_inheritance_private_member.cpp](exercises/protected_inheritance_private_member.cpp) | same task with PROTECTED inheritance |  |
| [vehicles_car_truck_bus.cpp](exercises/vehicles_car_truck_bus.cpp) | Samochod -&gt; Ciezarowka / Autobus: default + param ctors calling the base ctor | 🔧 fixed |
| [school_test_A_public_inheritance.cpp](exercises/school_test_A_public_inheritance.cpp) | test group A: public inheritance, protected field via derived getter/setter |  |
| [school_test_B_private_inheritance.cpp](exercises/school_test_B_private_inheritance.cpp) | test group B: private inheritance, base ctor call, getters/setters in the derived class |  |
| [school_test_delegating_constructors.cpp](exercises/school_test_delegating_constructors.cpp) | test: protected inheritance + one delegating ctor `Baza() : Baza(1, "tekst")` (shown once) |  |
| [school_test_protected_inheritance.cpp](exercises/school_test_protected_inheritance.cpp) | test: protected inheritance | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
