# 13_polymorphism - Polymorphism - virtual, pure virtual, abstract classes, base pointers

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [3_BUILDING_BLOCKS/08_classes.cpp](../../3_BUILDING_BLOCKS/08_classes.cpp)

```cpp
class Figura
{
public:
    virtual double pole()        // virtual = wersja wybierana w czasie dzialania, wg typu OBIEKTU
    {
        return 0;
    }
    virtual void rysuj() = 0;    // czysto wirtualna -> Figura jest ABSTRAKCYJNA (brak obiektow)
};

class Kolo : public Figura
{
private:
    double r;

public:
    Kolo(double promien)
    {
        r = promien;
    }
    double pole()                // ta sama nazwa i parametry co w bazie
    {
        return 3.14 * r * r;
    }
    void rysuj()
    {
        cout << "kolo" << endl;
    }
};

Kolo kolo(2);
Figura *wsk = &kolo;
cout << wsk->pole();             // Kolo::pole - dzieki virtual
```
Without `virtual`, a base pointer always calls the **base** version (see 02_). Objects can live on the stack (`Kolo k(2); Figura *wsk = &k;`) or the heap (`wsk = new Kolo(2); ... delete wsk;`) - for the heap version the base class also gets `virtual ~Figura() {}` (see 05_). `override` is optional and not needed at the exam.

## Files

| File | What it shows | |
|---|---|---|
| [01_method_redefinition_no_virtual.cpp](01_method_redefinition_no_virtual.cpp) | derived class redefines methods (no virtual, called directly on objects) |  |
| [02_base_pointer_without_virtual.cpp](02_base_pointer_without_virtual.cpp) | base-class pointer to a derived object WITHOUT virtual -&gt; base method is called (why you need virtual) | ⭐ 🔧 fixed |
| [03_virtual_on_heap_animals.cpp](03_virtual_on_heap_animals.cpp) | `Zwierze *z = new Lew(...)`, virtual method, delete | ⭐ |
| [04_pure_virtual_abstract_class.cpp](04_pure_virtual_abstract_class.cpp) | pure virtual `= 0`, abstract class Zwierze (no objects), Pies/Kot through a base pointer | ⭐ |
| [05_abstract_class_virtual_destructor_override.cpp](05_abstract_class_virtual_destructor_override.cpp) | `virtual ~Pojazd()` and the `override` keyword - when you need them (override: never at the exam) |  |
| [06_virtual_with_multiple_inheritance.cpp](06_virtual_with_multiple_inheritance.cpp) | virtual + multiple inheritance, `Imie::zwrocDane()` calls |  |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [shapes_area_heap.cpp](exercises/shapes_area_heap.cpp) | same shapes created with new/delete | 🔧 fixed |
| [shapes_area_stack.cpp](exercises/shapes_area_stack.cpp) | Figura -&gt; Trojkat/Rownoleglobok/Kolo, base pointer to stack objects | 🔧 fixed |
| [solids_volume.cpp](exercises/solids_volume.cpp) | Bryla -&gt; Walec -&gt; Stozek, Bryla -&gt; Prostopadloscian, virtual objetosc() | 🔧 fixed |
| [abstract_animal_dog_cat_parrot.cpp](exercises/abstract_animal_dog_cat_parrot.cpp) | task text + abstract Animal with 3 subclasses on the heap |  |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
