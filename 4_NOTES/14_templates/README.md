# 14_templates - Templates - function & class templates, specialization (specjalizacja) vs instantiation (konkretyzacja)

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [3_BUILDING_BLOCKS/12_templates.cpp](../../3_BUILDING_BLOCKS/12_templates.cpp)

```cpp
template <typename T>
T wieksza(T a, T b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
wieksza(3, 7);             // niejawnie (implicit) - T zgadniety z argumentow
wieksza<double>(3, 7.5);   // jawnie (explicit)

template <typename T1, typename T2>
class Para
{
public:
    T1 a;
    T2 b;
    T2 f();                                     // tylko deklaracja
};
template <typename T1, typename T2>
T2 Para<T1, T2>::f() { ... }                    // metoda poza klasa

template <> double g<double, float>(double a, float b) { ... }  // specjalizacja funkcji
template <> class Para<int, float> { ... };                     // specjalizacja calej klasy
template <> void Para<double, float>::pokaz() { ... }           // specjalizacja JEDNEJ metody

template class Para<char, char>;                                // konkretyzacja JAWNA
Para<int, int> p;                                               // konkretyzacja NIEJAWNA
```
**Konkretyzacja (instantiation)** = kompilator sam buduje wersję z ogólnego szablonu (niejawnie przy użyciu, albo jawnie linią `template class ...;`). **Specjalizacja (specialization)** = sam piszesz osobną wersję dla danych typów (`template <>`); ma pierwszeństwo przed szablonem ogólnym.

## Files

| File | What it shows | |
|---|---|---|
| [01_template_basics.cpp](01_template_basics.cpp) | the simplest templates - function template wieksza&lt;T&gt;, array-printing template, class template Pudelko&lt;T&gt; with a method outside, explicit vs implicit types | 🆕 added |
| [02_function_template_three_types.cpp](02_function_template_three_types.cpp) | template&lt;T1,T2,T3&gt; function with explicit types |  |
| [03_function_template_specialization.cpp](03_function_template_specialization.cpp) | function template + 2 full specializations template&lt;&gt;; specialization beats instantiation | ⭐ |
| [04_function_template_implicit_calls.cpp](04_function_template_implicit_calls.cpp) | implicit calls funkcja(a, b) choose the specialization from the argument types | 🔧 fixed |
| [05_class_template_specialization.cpp](05_class_template_specialization.cpp) | template&lt;T1,T2&gt; class Prostokat, method defined outside, full class specialization vs instantiation (konkretyzacja) | ⭐ |
| [06_specialize_one_method.cpp](06_specialize_one_method.cpp) | specialize ONE method: template&lt;&gt; void Szablon&lt;double,float&gt;::wyswietl() vs the whole class |  |
| [07_templates_all_in_one.cpp](07_templates_all_in_one.cpp) | summary: function spec, class spec, one-method spec, explicit (`template class ...;`) and implicit instantiation | ⭐ |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [class_template_average_price.cpp](exercises/class_template_average_price.cpp) | class template with a constructor + one full class specialization (average price) |  |
| [class_template_three_params.cpp](exercises/class_template_three_params.cpp) | 3 type parameters, 2 full class specializations |  |
| [specializations_pow_sum_product.cpp](exercises/specializations_pow_sum_product.cpp) | task: 3 specializations of a 2-parameter function template, explicit + implicit calls |  |
| [rectangle_specialization_vs_instantiation.cpp](exercises/rectangle_specialization_vs_instantiation.cpp) | task: specialization float,double + explicit instantiation int,float + implicit instantiation |  |
| [school_test_average_weather_product.cpp](exercises/school_test_average_weather_product.cpp) | test: specializations int,float / double,double + generic | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
