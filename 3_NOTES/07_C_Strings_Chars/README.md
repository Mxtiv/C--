# 07_C_Strings_Chars - C-strings (char[]) and characters (cctype)

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/06_strings.cpp](../../2_BUILDING_BLOCKS/06_strings.cpp)

```cpp
#include <cstring>
char t[30] = "Ala";            // always leave room for the '\0' terminator
cin >> t;                      // one word         cin.getline(t, 30);  // whole line
cin.get(t, 30); cin.ignore(50, '\n');                  // line, then clear the rest of the buffer
strlen(t)   strcpy(dst, src)   strcat(dst, src)   strcmp(a, b)  // 0 = equal, <0, >0
strncpy(dst, src, n); dst[n] = '\0';    // copy only n chars - add the '\0' yourself
strstr(t, "x")  strchr(t, 'a')          // pointer to the match or NULL; index = ptr - t
strtok(t, " ")                          // cut off the first word (modifies t)
for (int i = 0; t[i] != '\0'; i++)      // walk a C-string until the terminator
#include <cctype>
isalpha isdigit isalnum isupper islower isspace ispunct   toupper tolower
'7' - '0' == 7      'a' + 1 == 'b'      (int)'A' == 65
```

## Files

| File | What it shows | |
|---|---|---|
| [01_cctype_cheatsheet.txt](01_cctype_cheatsheet.txt) | reference text file |  |
| [01_cctype_functions.cpp](01_cctype_functions.cpp) | isalpha isdigit isalnum isupper islower isspace ispunct tolower toupper; counting digits in a text | ⭐ |
| [02_cstring_overview_cin_get_ignore.cpp](02_cstring_overview_cin_get_ignore.cpp) | char[] init, cin &gt;&gt;, cin.ignore(n,'\n'), cin.get(buf,n) with spaces, strcpy strlen strcmp strcat strstr (Polish comments) | ⭐ |
| [03_cstring_menu_all_tasks.cpp](03_cstring_menu_all_tasks.cpp) | switch menu: cin.getline into char[], strcat, strcmp, strstr + position (ptr - base), replace with strcpy + strcat | ⭐ 🔧 fixed |
| [04_replace_substring_strstr_strncat.cpp](04_replace_substring_strstr_strncat.cpp) | replace a substring using strstr + strncat into a new array; repeat with do-while |  |
| [05_insert_middle_name_strchr.cpp](05_insert_middle_name_strchr.cpp) | insert a middle name: strchr, strncpy, strcat |  |
| [06_find_all_letter_positions_strchr.cpp](06_find_all_letter_positions_strchr.cpp) | find all positions of a letter with a strchr loop |  |

### exercises/ - tests (sprawdziany), tasks and classmates' versions

| File | What it shows | |
|---|---|---|
| [ascii_shift_letter.cpp](exercises/ascii_shift_letter.cpp) | (int)char = ASCII code, shift a letter and wrap around the alphabet | 🔧 fixed |
| [count_letter_in_name.cpp](exercises/count_letter_in_name.cpp) | count a letter by looping until '\0'; strchr version | 🔧 fixed |
| [swap_words_v1_strchr.cpp](exercises/swap_words_v1_strchr.cpp) | swap the first words of two 2-word phrases (strchr + strncpy + strcat) | 🔧 fixed |
| [swap_words_v4_strtok.cpp](exercises/swap_words_v4_strtok.cpp) | cleanest swap version: strtok returns pointers |  |

---
⭐ best file to learn the topic from · 🆕 added to fill a gap · 🔧 bug fixed (the file header says what was wrong)
