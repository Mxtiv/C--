# 18_Preprocessor_Macros - Preprocessor - #include, #define, macros, conditional compilation

[⬅ notes index](../README.md) · [main index](../../README.md)

```cpp
#include <iostream>     // system/library header
#include "myheader.h"   // your own header (searched next to the .cpp first)
#define PI 3.14159                     // text replacement (prefer const double PI = ...)
#define SQUARE(x) ((x) * (x))          // ALWAYS wrap the argument and the whole thing in ()
#ifndef MY_H / #define MY_H / ... / #endif   // include guard
#if VERSION == 2 ... #elif ... #else ... #endif
#ifdef DEBUG ... #endif      #undef DEBUG
```

## Files

| File | What it shows | |
|---|---|---|
| [01_include_own_header.cpp](01_include_own_header.cpp) | #include &lt;...&gt; vs #include "myheader.h" |  |
| [02_define_constants_and_macros.cpp](02_define_constants_and_macros.cpp) | #define PI, #define SQUARE(x) ((x) * (x)) | ⭐ |
| [03_if_elif_else_endif.cpp](03_if_elif_else_endif.cpp) | #if / #elif / #else / #endif |  |
| [04_ifdef_undef.cpp](04_ifdef_undef.cpp) | #define, #undef, #ifdef |  |
| [05_feature_flags_ifdef.cpp](05_feature_flags_ifdef.cpp) | feature flags with #ifdef (Polish explanation) |  |
| [myheader.h](myheader.h) | include guard #ifndef / #define / #endif (this is the header 01_ includes) | ⭐ 🔧 fixed |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [macro_average.cpp](exercises/macro_average.cpp) | macro calc_avg(a, b) |  |
| [macro_is_even_cube.cpp](exercises/macro_is_even_cube.cpp) | IS_EVEN(n), CUBE(h) | 🔧 fixed |
| [macro_running_average.cpp](exercises/macro_running_average.cpp) | macro with the comma operator | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
