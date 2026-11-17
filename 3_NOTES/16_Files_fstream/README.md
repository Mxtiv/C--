# 16_Files_fstream - Files - ofstream, ifstream, fstream, append, reading loops

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/09_files.cpp](../../2_BUILDING_BLOCKS/09_files.cpp)

```cpp
#include <fstream>
ofstream out("file.txt");              // write (creates/overwrites)
ofstream app("file.txt", ios::app);    // append at the end
ifstream in("file.txt");               // read
if (!in) { cerr << "cannot open"; }    // ALWAYS check
while (in >> x) { }                    // read numbers/words - CORRECT loop
while (getline(in, line)) { }          // read lines
out.close();
```
Don't use `while (!in.eof())` - it handles the last value twice. Relative file names are looked up in the **current folder**, i.e. where you run the `.exe`.

## Files

| File | What it shows | |
|---|---|---|
| [01_random_numbers_file_average.cpp](01_random_numbers_file_average.cpp) | ofstream write, if(!plik) check, while(plik &gt;&gt; x) count, read into new int[], average | ⭐ 🔧 fixed |
| [02_write_read_append_sum.cpp](02_write_read_append_sum.cpp) | same + append the sum with ios::app | 🔧 fixed |
| [03_file_average_compact.cpp](03_file_average_compact.cpp) | compact correct version (while (plik &gt;&gt; x)) |  |

### exercises/file_to_dynamic_array/

| File | What it shows | |
|---|---|---|
| [fstream1.cpp](exercises/file_to_dynamic_array/fstream1.cpp) | count numbers, then read them into new int[] (fstream modes in comments) | 🔧 fixed |
| [wyjscie1.txt](exercises/file_to_dynamic_array/wyjscie1.txt) | data file read by the program in this folder |  |

### exercises/sum_from_file/

| File | What it shows | |
|---|---|---|
| [fstream.cpp](exercises/sum_from_file/fstream.cpp) | sum numbers from wyjscie.txt | 🔧 fixed |
| [wyjscie.txt](exercises/sum_from_file/wyjscie.txt) | data file read by the program in this folder |  |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [append_read_sum.cpp](exercises/append_read_sum.cpp) | append user numbers (ios::app), read them back, sum | 🔧 fixed |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
