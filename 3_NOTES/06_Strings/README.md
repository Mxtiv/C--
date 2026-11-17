# 06_Strings - std::string - operations, splitting, menus, algorithms, Caesar cipher

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/06_strings.cpp](../../2_BUILDING_BLOCKS/06_strings.cpp)

```cpp
#include <string>
s.length()  s.size()  s[i]  s.at(i)  s.empty()
s + t   s += "x"   s.append("x")   s == t   s < t        // compare alphabetically
s.substr(start, len)   s.find("x")  s.rfind('x')         // find returns string::npos if missing
s.insert(pos, "x")   s.erase(pos, len)   s.replace(pos, len, "x")
getline(cin, s);                                         // whole line with spaces
for (char &c : s) c = toupper(c);                        // #include <cctype>
stringstream ss(s); while (getline(ss, part, ',')) {}    // split by a delimiter (#include <sstream>)
istringstream in(s); while (in >> word) {}               // split by spaces
reverse(s.begin(), s.end());  stoi(s)  to_string(n)  s.c_str()
```

## Files

| File | What it shows | |
|---|---|---|
| [01_overview_string.cpp](01_overview_string.cpp) | length, substr, split (stringstream + getline with ','), find/rfind, replace, insert, erase, toupper/tolower via transform, npos, compare, stoi/stof, reverse, trim | ⭐ |
| [02_string_basics.cpp](02_string_basics.cpp) | concatenation, [] access, append, length, find, substr, ==, c_str() |  |
| [03_string_operations.cpp](03_string_operations.cpp) | concat, last char, substr, find, replace, erase, insert, compare, loop over chars |  |
| [04_split_words_istringstream.cpp](04_split_words_istringstream.cpp) | getline + istringstream &gt;&gt; word into vector&lt;string&gt; |  |
| [05_string_menu_tasks.cpp](05_string_menu_tasks.cpp) | switch menu with 6 std::string tasks; pass string&amp; / const string&amp;; cin.ignore() before getline |  |
| [06_string_menu_13_operations.cpp](06_string_menu_13_operations.cpp) | 13-option menu: std::replace, insert before every char, count pattern (pair + vector), tuple, structured bindings auto [a,b], toggle case with char&amp; | ⭐ |
| [07_caesar_cipher.cpp](07_caesar_cipher.cpp) | Caesar cipher +3 encrypt / decrypt (lowercase, wraps around) |  |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [getline_find_space.cpp](exercises/getline_find_space.cpp) | getline(cin, s) + find(" ") | 🔧 fixed |
| [string_divider_combine_digits.cpp](exercises/string_divider_combine_digits.cpp) | combine chosen digits: result += s.substr(pos,1); stoi |  |
| [string_divider_static_const_switch.cpp](exercises/string_divider_static_const_switch.cpp) | static const int size, digit = char - 48, switch |  |
| [string_divider_substr_stoi.cpp](exercises/string_divider_substr_stoi.cpp) | class splitting a 15-digit string with substr + stoi; sizeof(arr)/sizeof(arr[0]) |  |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
