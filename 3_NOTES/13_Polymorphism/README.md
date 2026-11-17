# 13_Polymorphism - Polymorphism - virtual, pure virtual, abstract classes, base pointers

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/08_classes.cpp](../../2_BUILDING_BLOCKS/08_classes.cpp)

```cpp
class Shape {
public:
    virtual double area() const { return 0; }   // virtual = decided at RUNTIME
    virtual void draw() = 0;                    // pure virtual -> Shape is ABSTRACT (no objects)
    virtual ~Shape() {}                         // ALWAYS virtual destructor in a base class
};
class Circle : public Shape {
public:
    double area() const override { ... }        // override = compiler checks the signature
    void draw() override { ... }
};
Shape *s = new Circle(2);   s->area();   delete s;   // calls Circle::area
```
Without `virtual`, a base pointer always calls the **base** version (see 02_). Objects can live on the stack (`Circle c; Shape *s = &c;`) or the heap (`new` / `delete`).

## Files

| File | What it shows | |
|---|---|---|
| [01_method_redefinition_no_virtual.cpp](01_method_redefinition_no_virtual.cpp) | derived class redefines methods (no virtual, called directly on objects) |  |
| [02_base_pointer_without_virtual.cpp](02_base_pointer_without_virtual.cpp) | base-class pointer to derived objects WITHOUT virtual -&gt; base method is called (why you need virtual) | ⭐ 🔧 fixed |
| [03_virtual_on_heap_animals.cpp](03_virtual_on_heap_animals.cpp) | Zwierze* = new Lew/Pies/Kot, virtual method, delete | ⭐ 🔧 fixed |
| [04_pure_virtual_abstract_class.cpp](04_pure_virtual_abstract_class.cpp) | pure virtual = 0, abstract class Animal, Dog/Cat on the heap | 🔧 fixed |
| [05_abstract_class_virtual_destructor_override.cpp](05_abstract_class_virtual_destructor_override.cpp) | virtual ~Base(), pure virtual const = 0, override keyword | ⭐ |
| [06_virtual_with_multiple_inheritance.cpp](06_virtual_with_multiple_inheritance.cpp) | virtual + multiple inheritance, Base::method() calls |  |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [shapes_area_heap.cpp](exercises/shapes_area_heap.cpp) | same shapes created with new/delete | 🔧 fixed |
| [shapes_area_stack.cpp](exercises/shapes_area_stack.cpp) | Figury -&gt; Trojkat/Rownoleglobok/Kolo, base pointer to stack objects | 🔧 fixed |
| [solids_volume.cpp](exercises/solids_volume.cpp) | corrected solids version (r*r) | 🔧 fixed |
| [task_abstract_animal_dog_cat_parrot.cpp](exercises/task_abstract_animal_dog_cat_parrot.cpp) | task text + abstract Animal with 3 subclasses on the heap | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
