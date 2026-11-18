# 06_Strings - std::string - operations, splitting, menus, algorithms, Caesar cipher

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/06_strings.cpp](../../2_BUILDING_BLOCKS/06_strings.cpp)

```cpp
#include <string>
s.length()  s[i]  s + t  s == t  s < t                   // s < t: compare alphabetically
s.substr(start, len)   s.find("x")  s.rfind('x')         // find gives string::npos if missing
if (s.find("x") != string::npos) { ... }
s.insert(pos, "x")   s.erase(pos, len)   s.replace(pos, len, "x")
getline(cin, s);                                         // whole line (cin.ignore(); first if cin >> was before)
for (int i = 0; i < (int)s.length(); i++)                // walk the string character by character
{
    s[i] = toupper(s[i]);                                // #include <cctype>
}
wynik = wynik + s[i];                                    // build a new string (reverse, split, insert)
stoi(s)  stod(s)  to_string(n)  s.c_str()
```

## Files

| File | What it shows | |
|---|---|---|
| [01_overview_string.cpp](01_overview_string.cpp) | length, substr, find/rfind + npos, replace, insert, erase, toupper/tolower in a loop, compare, stoi/stod, reverse by hand, split by ',' by hand | ⭐ |
| [02_string_basics.cpp](02_string_basics.cpp) | concatenation, [] access and change, append, length, ==, loop over chars, c_str() |  |
| [03_string_operations.cpp](03_string_operations.cpp) | substr, find + npos, replace, erase, insert - editing a string step by step |  |
| [04_split_words_istringstream.cpp](04_split_words_istringstream.cpp) | getline + istringstream &gt;&gt; word into an array of words + count |  |
| [05_string_menu_tasks.cpp](05_string_menu_tasks.cpp) | switch menu with 6 std::string tasks; string&amp; to read several values; cin.ignore() before getline |  |
| [06_string_menu_13_operations.cpp](06_string_menu_13_operations.cpp) | 13-option menu: swap first/last word, replace characters, insert before a character, count a pattern with indexes, count letters/digits, toggle case | ⭐ |
| [07_caesar_cipher.cpp](07_caesar_cipher.cpp) | Caesar cipher +3 encrypt / decrypt (lowercase, wraps around) |  |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [getline_find_space.cpp](exercises/getline_find_space.cpp) | getline(cin, s) + find(" ") | 🔧 fixed |
| [string_divider_combine_digits.cpp](exercises/string_divider_combine_digits.cpp) | combine chosen digits: wynik = wynik + s.substr(pos, 1); stoi |  |
| [string_divider_static_const_switch.cpp](exercises/string_divider_static_const_switch.cpp) | static const int ROZMIAR in a class, digit = char - '0', switch |  |
| [string_divider_substr_stoi.cpp](exercises/string_divider_substr_stoi.cpp) | class splitting a 15-digit string with substr + stoi |  |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
