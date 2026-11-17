# 17_Math_Algorithms - Math & number algorithms - cmath, NWD/NWW, primes, Fibonacci, number systems, PESEL

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/05_numbers.cpp](../../2_BUILDING_BLOCKS/05_numbers.cpp) · [2_BUILDING_BLOCKS/07_pesel.cpp](../../2_BUILDING_BLOCKS/07_pesel.cpp)

```cpp
#include <cmath>
sqrt(x) pow(a, b) abs(x) round(x) ceil(x) floor(x) trunc(x) sin(x) log(x) log10(x) M_PI
NWD (GCD): while (b != 0) { int t = a % b; a = b; b = t; }  -> a
NWW (LCM): a / nwd(a, b) * b
prime:     for (d = 2; d * d <= n; d++) if (n % d == 0) -> not prime
```
**PESEL** (11 digits, index 0-10): weights `1 3 7 9 1 3 7 9 1 3` for digits 0-9; `S = Σ digit·weight`; control = `(10 - S % 10) % 10`, must equal digit 10. Sex = digit **9** (even = woman). Month +20 → 2000s, +80 → 1800s. Remember `pesel[i] - '0'`. The correct compact version is `pesel/01_pesel_correct_compact.cpp`.

## Files

| File | What it shows | |
|---|---|---|
| [01_cmath_functions.cpp](01_cmath_functions.cpp) | abs sqrt pow log exp log10 sin cos tan ceil floor trunc round | ⭐ |
| [02_rounding_ceil_floor_trunc_round.cpp](02_rounding_ceil_floor_trunc_round.cpp) | rounding table incl. negative numbers |  |
| [03_gcd_lcm_nwd_nww.cpp](03_gcd_lcm_nwd_nww.cpp) | GCD (Euclid, modulo version) and LCM | ⭐ |

### pesel/

| File | What it shows | |
|---|---|---|
| [01_pesel_correct_compact.cpp](pesel/01_pesel_correct_compact.cpp) | CORRECT PESEL: weights array, (10 - S%10) % 10, - '0', century from month (+80/+20) | ⭐ |
| [02_pesel_doc_comments_birthdate.cpp](pesel/02_pesel_doc_comments_birthdate.cpp) | INF04-style doc comment, sex, checksum, birth date | 🔧 fixed |
| [03_pesel_classes_date.cpp](pesel/03_pesel_classes_date.cpp) | class date + class pesel, .at(), method returns an object | 🔧 fixed |
| [04_pesel_class_private_validation.cpp](pesel/04_pesel_class_private_validation.cpp) | private validation method used by a public setter, getters via reference params, local struct, leading zeros | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
