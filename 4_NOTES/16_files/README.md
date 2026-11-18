# 16_files - Files - ofstream, ifstream, fstream, append, reading loops

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [3_BUILDING_BLOCKS/09_files.cpp](../../3_BUILDING_BLOCKS/09_files.cpp)

```cpp
#include <fstream>
ofstream zapis("plik.txt");              // zapis (tworzy / nadpisuje)
ofstream dopisz("plik.txt", ios::app);   // dopisywanie na koncu
ifstream odczyt("plik.txt");             // odczyt
if (!odczyt)                             // ZAWSZE sprawdz
{
    cout << "Nie mozna otworzyc pliku";
}
while (odczyt >> liczba)                 // liczby / slowa - POPRAWNA petla
{
}
while (getline(odczyt, linia))           // cale linie
{
}
odczyt.close();
```
Don't use `while (!plik.eof())` - it handles the last value twice. Relative file names are looked up in the **current folder**, i.e. where you run the `.exe`.

## Files

| File | What it shows | |
|---|---|---|
| [01_random_numbers_file_average.cpp](01_random_numbers_file_average.cpp) | ofstream write, if (!plik) check, while (plik &gt;&gt; x) read into an array + count, average | ⭐ 🔧 fixed |
| [02_write_read_append_sum.cpp](02_write_read_append_sum.cpp) | write, read + sum, append the sum with ios::app, read lines with getline | ⭐ 🔧 fixed |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [append_read_sum.cpp](exercises/append_read_sum.cpp) | append user numbers (ios::app), read them back, sum | 🔧 fixed |
| [file_to_dynamic_array.cpp](exercises/file_to_dynamic_array.cpp) | count numbers, then read them into new int[] (fstream modes ios::in / out / app in comments); reads [numbers_input.txt](exercises/numbers_input.txt) - run it from the `exercises` folder | 🔧 fixed |
| [sum_from_file.cpp](exercises/sum_from_file.cpp) | sum numbers from wyjscie.txt (create that file yourself - wyjscie.txt is git-ignored) | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
