# 14_Templates - Templates - function & class templates, specialization (specjalizacja) vs instantiation (konkretyzacja)

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/12_templates.cpp](../../2_BUILDING_BLOCKS/12_templates.cpp)

```cpp
template <typename T> T maxOf(T a, T b) { return a > b ? a : b; }
maxOf(3, 7);           // implicit (niejawne) - T deduced
maxOf<double>(3, 7.5); // explicit (jawne)

template <typename T1, typename T2> class Para { T1 a; T2 b; ... };
template <typename T1, typename T2> T2 Para<T1,T2>::f() { ... }   // method outside

template <> double f<double, float>(double a, float b) { ... }   // full specialization of a function
template <> class Para<int, float> { ... };                       // full specialization of a class
template <> void Para<double, float>::show() { ... }              // specialize ONE method
```
Instantiation (konkretyzacja) = the compiler builds a version from the general template. Specialization = you write a special version for given types; it wins over the general template.

## Files

| File | What it shows | |
|---|---|---|
| [01_template_basics.cpp](01_template_basics.cpp) | the simplest templates - one-type function template, class template Box&lt;T&gt;, explicit vs implicit (deduced) types, non-type parameter | 🆕 added |
| [02_function_template_three_types.cpp](02_function_template_three_types.cpp) | template&lt;T1,T2,T3&gt; function with explicit types |  |
| [03_function_template_specialization.cpp](03_function_template_specialization.cpp) | function template + 2 full specializations template&lt;&gt;; specialization beats instantiation | ⭐ |
| [04_function_template_implicit_calls.cpp](04_function_template_implicit_calls.cpp) | implicit calls funkcja(a, b) choose the specialization from the argument types | 🔧 fixed |
| [05_class_template_specialization.cpp](05_class_template_specialization.cpp) | template&lt;T1,T2&gt; class Prostokat, method defined outside, full class specializations vs instantiation (konkretyzacja) | ⭐ |
| [06_specialize_one_method.cpp](06_specialize_one_method.cpp) | specialize ONE method: template&lt;&gt; void Szablon&lt;double,float&gt;::display() |  |
| [07_templates_all_in_one.cpp](07_templates_all_in_one.cpp) | function template + specs, class template with per-method specs, class specialization | ⭐ |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [class_template_ctad.cpp](exercises/class_template_ctad.cpp) | class template with ctor; CTAD: Komorka k(10, 5.5f) without &lt;&gt; (C++17) |  |
| [class_template_three_params.cpp](exercises/class_template_three_params.cpp) | 3 type parameters, 2 full class specializations |  |
| [task1_pow_sum_product.cpp](exercises/task1_pow_sum_product.cpp) | task: 3 specializations of a 2-parameter function template |  |
| [task_rectangle_spec_vs_instantiation.cpp](exercises/task_rectangle_spec_vs_instantiation.cpp) | task: specialization float,double + instantiation int,float |  |
| [test_avg_weather_product.cpp](exercises/test_avg_weather_product.cpp) | test: specializations int,float / double,double + generic | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
