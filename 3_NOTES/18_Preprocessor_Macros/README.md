# 18_Preprocessor_Macros - Preprocessor - #include, #define, macros, conditional compilation

[⬅ notes index](../README.md) · [main index](../../README.md)

```cpp
#include <iostream>       // naglowek biblioteki
#include "myheader.h"     // WLASNY naglowek (szukany najpierw obok .cpp)

#define PI 3.14159                // podmiana tekstu (na egzaminie lepiej: const double PI = 3.14159;)
#define KWADRAT(x) ((x) * (x))    // ZAWSZE nawiasy wokol x i calosci

#ifndef MOJ_H                     // include guard - w kazdym pliku .h
#define MOJ_H
// ... zawartosc naglowka ...
#endif

#if WERSJA == 2                   // kompilacja warunkowa
#elif WERSJA == 1
#else
#endif

#ifdef DEBUG                      // czy DEBUG jest zdefiniowane?
#endif
#undef DEBUG                      // usun definicje
```

## Files

| File | What it shows | |
|---|---|---|
| [01_include_own_header.cpp](01_include_own_header.cpp) | #include &lt;...&gt; vs #include "myheader.h", included twice - the guard makes it safe |  |
| [02_define_constants_and_macros.cpp](02_define_constants_and_macros.cpp) | #define PI, #define KWADRAT(x) ((x) * (x)) and why the brackets matter | ⭐ |
| [03_if_elif_else_endif.cpp](03_if_elif_else_endif.cpp) | #if / #elif / #else / #endif |  |
| [04_ifdef_undef.cpp](04_ifdef_undef.cpp) | #define, #undef, #ifdef |  |
| [05_feature_flags_ifdef.cpp](05_feature_flags_ifdef.cpp) | feature flags with #ifdef (Polish explanation) |  |
| [myheader.h](myheader.h) | include guard #ifndef / #define / #endif (this is the header 01_ includes) | ⭐ 🔧 fixed |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [macro_average.cpp](exercises/macro_average.cpp) | macro SREDNIA(a, b) |  |
| [macro_is_even_cube.cpp](exercises/macro_is_even_cube.cpp) | CZY_PARZYSTA(n), SZESCIAN(x) | 🔧 fixed |
| [macro_running_average.cpp](exercises/macro_running_average.cpp) | macro that changes two variables (suma, licznik) - running average | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
