# C++ toolbox for INF.04

The console part of my INF.04 toolbox (siblings: `inf04-react` for web, `inf04-desktop` for C# WinForms).
Code you can **take straight into a program** you're writing, sorted so you can find it fast. **Every official INF.04 console task 2021–2026 is solved.** Everything compiles with g++ and MSVC and is checked by `9_SELF_TESTS`.
All code is written in one **plain exam style** (arrays + loops, no fancy library tricks) - see [CODE_STYLE.md](CODE_STYLE.md).

## What do you need? → go here

| I need… | Open |
|---|---|
| **the exact task from a past exam** (all 20 console tasks 2021–2026, SG + SD/AG) | [1_EXAM_TASKS](1_EXAM_TASKS/README.md): one folder per task with the **sheet**, the **grading key**, `main.cpp` and a README (task, key checklist, comment pattern); see the [table below](#official-exam-tasks-20212026) |
| **a program similar to my task** (topic mix) | [2_PRACTICE](2_PRACTICE/README.md): 16 programs in learning order |
| **unit tests in C++** (Visual Studio Native Unit Test, offline) | [string_caesar_cipher_unit_tests__2025-06_task2](1_EXAM_TASKS/string_caesar_cipher_unit_tests__2025-06_task2/README.md), [class_dice_unit_tests__2026-01_task1](1_EXAM_TASKS/class_dice_unit_tests__2026-01_task1/README.md) |
| the **official sheet / grading key** of a task | inside the task's folder (`exam_sheet_….pdf`, `grading_key_….pdf/.xlsx`); index of all 31 sheets: [1_EXAM_TASKS](1_EXAM_TASKS/README.md#all-sheets-and-grading-keys) |
| **one function / pattern** (search, sort, input check, class, file…) | [3_BUILDING_BLOCKS](3_BUILDING_BLOCKS/README.md): 119 blocks; the [task phrase → block](#task-phrase--block) table, or Ctrl+F in the [catalog](#building-blocks---full-catalog) |
| an **empty program to start from** (includes, `srand`, comment boxes, hand-in checklist) | [3_BUILDING_BLOCKS/00_start_template.cpp](3_BUILDING_BLOCKS/00_start_template.cpp) |
| the **documentation comment** (nazwa funkcji / opis / parametry / zwracany typ / autor) | every block already has one; empty boxes are in the start template |
| to **understand** how something works | [4_NOTES](4_NOTES/README.md): topic chapters |

**Folders** (numbered in the order you'll usually need them):

| Folder | What's inside | Use it when |
|---|---|---|
| **[1_EXAM_TASKS](1_EXAM_TASKS/README.md)** | the 20 official console tasks, one folder each: sheet(s) + key(s) + solution | the task is (or looks like) one you've seen - copy it and adapt |
| **[2_PRACTICE](2_PRACTICE/README.md)** | 16 exam-style programs, numbered from easiest to hardest | a new task mixes topics - start from the closest one |
| **[3_BUILDING_BLOCKS](3_BUILDING_BLOCKS/README.md)** | 119 paste-ready functions, class skeletons and patterns, each with the INF.04 comment box | you need one piece: a search, a sort, input validation, a class … |
| [4_NOTES](4_NOTES/README.md) | topic chapters (basics → templates): cheat sheets, explanations, your old files and tests | you need to understand *how* something works |
| [9_SELF_TESTS](9_SELF_TESTS/README.md) | scripts that compile and run everything | after changing the toolbox (not needed at the exam) |

## How names work

Every name says **what** is inside first, so a folder listing reads like a table of contents.

| Where | Pattern | Example | Read it as |
|---|---|---|---|
| exam task folder | `<category>_<topic>__<YYYY-MM>_task<N>` | `sort_bubble_with_test__2023-06_task2` | bubble sort + test, exam session June 2023, task 2 (= INF.04-**02**-**23.06**-SG) |
| sheet / key in a task folder | `exam_sheet_<YYYY-MM>_task<N>_<SG/SD/AG>.pdf`, `grading_key_….pdf/.xlsx` | `exam_sheet_2024-06_task1_SD.pdf` | sheet INF.04-01-24.06-SD (SG = main session, SD = extra date, AG = adapted version) |
| practice program | `<NN>_<topic>.cpp` | `07_dice_game.cpp` | 7th in learning order |
| building block file | `<NN>_<topic>.cpp`, the blocks inside have IDs | `03_arrays.cpp` → `ARR-14` | arrays, block 14 |
| notes | `<NN>_<chapter>/<NN>_<what it shows>.cpp`; tasks in `exercises/` (`school_test_…` = a test from school) | `11_classes/05_copy_constructor_minimal.cpp` | chapter 11, file 5 |

Exam task categories, so similar tasks sit next to each other: `class_` (9 tasks, the most common), `sort_`, `search_`, `math_`, `string_`, `random_`, `game_`, `file_`, `pesel_`.
Names stay as they are where the exam or C++ decides them: `main.cpp`, files given with the sheet (`Data.txt`, `znaki.txt`), a class's `.h`/`.cpp` named after the class, and the Visual Studio projects (`SzyfrCezara`, `Kosc`).

## Writing a task - the workflow

1. **Is it a past exam task?** Open its folder from the [official tasks table](#official-exam-tasks-20212026); same topic = same category prefix. **Similar to a practice program?** Copy it and change what's different.
2. **Otherwise** copy [00_start_template.cpp](3_BUILDING_BLOCKS/00_start_template.cpp) (includes + `srand` + empty comment boxes) and paste the blocks you need from the catalog below. Search by **what you need** (Ctrl+F: "random", "sort", "index", "file" …) or by **ID**.
3. **In VS Code** (open the `C--` folder): type a block's function name or its ID without the dash (`arr14`, `sort03`, `cls03`) and press **Tab** - the block is inserted with its comment box.
4. Before handing in, go through the checklist at the bottom of the start template.
5. Write it the way [CODE_STYLE.md](CODE_STYLE.md) shows: plain arrays, your own loops, `if/else`, simple `cin` loops.

> At the real exam you won't have this folder. The blocks are deliberately short and use the same patterns everywhere, so pasting them while you practise also helps you learn them.

## Ready programs

### Official exam tasks 2021–2026

Sorted by topic. The sheet and grading key are inside each folder.

| Folder | Exam | Task |
|---|---|---|
| [**class_abstract_quiz__2026-01_task2**](1_EXAM_TASKS/class_abstract_quiz__2026-01_task2/README.md) | 02-26.01-SG | Quiz – klasa abstrakcyjna Pytanie + PytanieZamkniete |
| [**class_array_operations__2025-01_task1**](1_EXAM_TASKS/class_array_operations__2025-01_task1/README.md) | 01-25.01-SG | Klasa z tablicą – operacje (wyszukiwanie, nieparzyste, średnia) |
| [**class_dice_unit_tests__2026-01_task1**](1_EXAM_TASKS/class_dice_unit_tests__2026-01_task1/README.md) | 01-26.01-SG | Klasa Kosc + testy jednostkowe (Visual Studio) |
| [**class_inheritance_home_devices__2025-01_task2**](1_EXAM_TASKS/class_inheritance_home_devices__2025-01_task2/README.md) | 02-25.01-SG (= 01-25.06-SD) | Urządzenia domowe – dziedziczenie (pralka, odkurzacz) |
| [**class_movie_get_set__2023-06_task3**](1_EXAM_TASKS/class_movie_get_set__2023-06_task3/README.md) | 03-23.06-SG (= 01-23.06-SD) | Klasa film (get, set, inkrementuj) |
| [**class_note_static_counter__2023-01_task2**](1_EXAM_TASKS/class_note_static_counter__2023-01_task2/README.md) | 02-23.01-SG (+ 23.01-01-SD, 23.01-02-AG) | Klasa notatka (licznik statyczny) |
| [**class_note_with_date__2026-06_task2**](1_EXAM_TASKS/class_note_with_date__2026-06_task2/README.md) | 02-26.06-SG | Klasa Notatka z datą dodania |
| [**class_person_static_counter__2022-06_task2**](1_EXAM_TASKS/class_person_static_counter__2022-06_task2/README.md) | 02-22.06-SG | Klasa Osoba (forum, pole statyczne) |
| [**class_static_string_tools__2024-01_task2**](1_EXAM_TASKS/class_static_string_tools__2024-01_task2/README.md) | 02-24.01-SG (+ 24.01-02-AG, 24.01-01-SD, 24.06-01-SD) | Klasa narzędzi dla napisów (samogłoski, powtórzenia) |
| [**file_music_albums__2024-06_task2**](1_EXAM_TASKS/file_music_albums__2024-06_task2/README.md) | 02-24.06-SG | Albumy muzyczne z pliku (Data.txt) |
| [**game_dice__2024-06_task1**](1_EXAM_TASKS/game_dice__2024-06_task1/README.md) | 01-24.06-SG (= 01-25.01-SD) | Gra w kości |
| [**math_gcd_euclid__2023-01_task1**](1_EXAM_TASKS/math_gcd_euclid__2023-01_task1/README.md) | 01-23.01-SG (+ AG) | NWD – algorytm Euklidesa |
| [**math_sieve_of_eratosthenes__2023-06_task1**](1_EXAM_TASKS/math_sieve_of_eratosthenes__2023-06_task1/README.md) | 01-23.06-SG | Sito Eratostenesa (n = 100) |
| [**pesel_sex_and_checksum__2024-01_task1**](1_EXAM_TASKS/pesel_sex_and_checksum__2024-01_task1/README.md) | 01-24.01-SG | PESEL – płeć i suma kontrolna |
| [**random_lottery_sets__2025-06_task1**](1_EXAM_TASKS/random_lottery_sets__2025-06_task1/README.md) | 01-25.06-SG (+ AG) | Loteria – zestawy 6 liczb z 49 |
| [**random_password_generator__2026-06_task1**](1_EXAM_TASKS/random_password_generator__2026-06_task1/README.md) | 01-26.06-SG | Generator bezpiecznych haseł (12 znaków) |
| [**search_with_sentinel__2022-06_task1**](1_EXAM_TASKS/search_with_sentinel__2022-06_task1/README.md) | 01-22.06-SG | Wyszukiwanie z wartownikiem |
| [**sort_bubble_with_test__2023-06_task2**](1_EXAM_TASKS/sort_bubble_with_test__2023-06_task2/README.md) | 02-23.06-SG | Sortowanie bąbelkowe + test |
| [**sort_selection_descending__2021-06_task1**](1_EXAM_TASKS/sort_selection_descending__2021-06_task1/README.md) | 01-21.06-SG (= 01-22.01-SG) | Sortowanie przez wybieranie (malejąco, klasa) |
| [**string_caesar_cipher_unit_tests__2025-06_task2**](1_EXAM_TASKS/string_caesar_cipher_unit_tests__2025-06_task2/README.md) | 02-25.06-SG | Szyfr Cezara + testy jednostkowe (Visual Studio) |

### Practice programs

In learning order: basics → algorithms → text → files → classes.

| # | Program | Built from blocks |
|---|---|---|
| 01 | [**01_number_guessing_game.cpp**](2_PRACTICE/01_number_guessing_game.cpp)<br>number guessing game - random 1..100, hints "za malo / za duzo", attempt counter, play again | [RND-01](3_BUILDING_BLOCKS/02_random.cpp#L13) [IO-01](3_BUILDING_BLOCKS/01_input_output.cpp#L12) [IO-04](3_BUILDING_BLOCKS/01_input_output.cpp#L72) |
| 02 | [**02_numbers_menu.cpp**](2_PRACTICE/02_numbers_menu.cpp)<br>number menu - prime?, perfect?, factorial, Fibonacci, NWD, decimal -&gt; binary, digit sum. Shows how to wire blocks into a menu program. | [IO-01](3_BUILDING_BLOCKS/01_input_output.cpp#L12) [IO-05](3_BUILDING_BLOCKS/01_input_output.cpp#L96) [NUM-01](3_BUILDING_BLOCKS/05_numbers.cpp#L15) [NUM-18](3_BUILDING_BLOCKS/05_numbers.cpp#L389) [NUM-08](3_BUILDING_BLOCKS/05_numbers.cpp#L184) [NUM-12](3_BUILDING_BLOCKS/05_numbers.cpp#L257) [NUM-04](3_BUILDING_BLOCKS/05_numbers.cpp#L97) [NUM-24](3_BUILDING_BLOCKS/05_numbers.cpp#L549) [NUM-13](3_BUILDING_BLOCKS/05_numbers.cpp#L279) |
| 03 | [**03_gcd_euclid_and_lcm.cpp**](2_PRACTICE/03_gcd_euclid_and_lcm.cpp)<br>NWD (GCD) by Euclid - subtraction AND modulo versions - and NWW (LCM) | [NUM-05](3_BUILDING_BLOCKS/05_numbers.cpp#L118) [NUM-04](3_BUILDING_BLOCKS/05_numbers.cpp#L97) [NUM-07](3_BUILDING_BLOCKS/05_numbers.cpp#L170) [IO-01](3_BUILDING_BLOCKS/01_input_output.cpp#L12) |
| 04 | [**04_sieve_of_eratosthenes.cpp**](2_PRACTICE/04_sieve_of_eratosthenes.cpp)<br>sieve of Eratosthenes - all primes from 2 to n | [NUM-02](3_BUILDING_BLOCKS/05_numbers.cpp#L39) [IO-01](3_BUILDING_BLOCKS/01_input_output.cpp#L12) |
| 05 | [**05_bubble_sort_dynamic_array.cpp**](2_PRACTICE/05_bubble_sort_dynamic_array.cpp)<br>bubble sort - size from the user, random fill, display before / after, ascending and descending | [SORT-01](3_BUILDING_BLOCKS/04_sorting.cpp#L14) [SORT-02](3_BUILDING_BLOCKS/04_sorting.cpp#L46) [RND-02](3_BUILDING_BLOCKS/02_random.cpp#L27) [ARR-02](3_BUILDING_BLOCKS/03_arrays.cpp#L32) [ARR-22](3_BUILDING_BLOCKS/03_arrays.cpp#L497) [IO-01](3_BUILDING_BLOCKS/01_input_output.cpp#L12) |
| 06 | [**06_search_with_sentinel.cpp**](2_PRACTICE/06_search_with_sentinel.cpp)<br>linear search WITH A SENTINEL (wyszukiwanie z wartownikiem) | [ARR-16](3_BUILDING_BLOCKS/03_arrays.cpp#L347) [RND-02](3_BUILDING_BLOCKS/02_random.cpp#L27) [ARR-02](3_BUILDING_BLOCKS/03_arrays.cpp#L32) [IO-01](3_BUILDING_BLOCKS/01_input_output.cpp#L12) |
| 07 | [**07_dice_game.cpp**](2_PRACTICE/07_dice_game.cpp)<br>dice game (gra w kości) - roll 3..10 dice, points = sum of the values that appeared at least twice, "play again? (t/n)" | [IO-01](3_BUILDING_BLOCKS/01_input_output.cpp#L12) [IO-04](3_BUILDING_BLOCKS/01_input_output.cpp#L72) [RND-02](3_BUILDING_BLOCKS/02_random.cpp#L27) [ARR-19](3_BUILDING_BLOCKS/03_arrays.cpp#L425) |
| 08 | [**08_text_analysis.cpp**](2_PRACTICE/08_text_analysis.cpp)<br>text analysis - length, words, vowels, consonants, digits, upper/lower case, palindrome, reversed, UPPER CASE, letter frequency | [IO-03](3_BUILDING_BLOCKS/01_input_output.cpp#L56) [STR-03](3_BUILDING_BLOCKS/06_strings.cpp#L47) [STR-04](3_BUILDING_BLOCKS/06_strings.cpp#L69) [STR-05](3_BUILDING_BLOCKS/06_strings.cpp#L94) [STR-07](3_BUILDING_BLOCKS/06_strings.cpp#L137) [STR-10](3_BUILDING_BLOCKS/06_strings.cpp#L228) [STR-11](3_BUILDING_BLOCKS/06_strings.cpp#L246) [STR-01](3_BUILDING_BLOCKS/06_strings.cpp#L13) [STR-20](3_BUILDING_BLOCKS/06_strings.cpp#L474) [STR-22](3_BUILDING_BLOCKS/06_strings.cpp#L542) |
| 09 | [**09_caesar_cipher.cpp**](2_PRACTICE/09_caesar_cipher.cpp)<br>Caesar cipher - encrypt / decrypt a whole line with any key, keeps upper/lower case, leaves spaces and other characters unchanged | [STR-14](3_BUILDING_BLOCKS/06_strings.cpp#L327) [STR-15](3_BUILDING_BLOCKS/06_strings.cpp#L358) [IO-03](3_BUILDING_BLOCKS/01_input_output.cpp#L56) [IO-05](3_BUILDING_BLOCKS/01_input_output.cpp#L96) |
| 10 | [**10_password_generator.cpp**](2_PRACTICE/10_password_generator.cpp)<br>password generator - length + options (uppercase, digits, special characters), generates several passwords | [RND-07](3_BUILDING_BLOCKS/02_random.cpp#L126) [IO-01](3_BUILDING_BLOCKS/01_input_output.cpp#L12) [IO-04](3_BUILDING_BLOCKS/01_input_output.cpp#L72) |
| 11 | [**11_pesel_checker.cpp**](2_PRACTICE/11_pesel_checker.cpp)<br>PESEL checker - format, control digit, sex, birth date | [PESEL-01](3_BUILDING_BLOCKS/07_pesel.cpp#L16) [PESEL-03](3_BUILDING_BLOCKS/07_pesel.cpp#L59) [PESEL-04](3_BUILDING_BLOCKS/07_pesel.cpp#L95) [PESEL-05](3_BUILDING_BLOCKS/07_pesel.cpp#L113) |
| 12 | [**12_file_numbers_statistics.cpp**](2_PRACTICE/12_file_numbers_statistics.cpp)<br>files - write n random numbers to a file, read them back, display, min / max / sum / average, append the result to the file | [FILE-01](3_BUILDING_BLOCKS/09_files.cpp#L14) [FILE-03](3_BUILDING_BLOCKS/09_files.cpp#L61) [FILE-02](3_BUILDING_BLOCKS/09_files.cpp#L40) [ARR-05](3_BUILDING_BLOCKS/03_arrays.cpp#L92) [ARR-06](3_BUILDING_BLOCKS/03_arrays.cpp#L114) [ARR-03](3_BUILDING_BLOCKS/03_arrays.cpp#L50) [ARR-04](3_BUILDING_BLOCKS/03_arrays.cpp#L69) [IO-01](3_BUILDING_BLOCKS/01_input_output.cpp#L12) |
| 13 | [**13_class_array_search_min_max.cpp**](2_PRACTICE/13_class_array_search_min_max.cpp)<br>class holding an array - display "i: value", search returning the indexes or -1, values divisible by k (display + count), product, min/max, average. THE most common INF.04 C++ task (your groups A and B). | [CLS-03](3_BUILDING_BLOCKS/08_classes.cpp#L146) [ARR-01](3_BUILDING_BLOCKS/03_arrays.cpp#L15) [ARR-14](3_BUILDING_BLOCKS/03_arrays.cpp#L296) [ARR-11](3_BUILDING_BLOCKS/03_arrays.cpp#L227) [ARR-10](3_BUILDING_BLOCKS/03_arrays.cpp#L208) [ARR-07](3_BUILDING_BLOCKS/03_arrays.cpp#L136) [ARR-04](3_BUILDING_BLOCKS/03_arrays.cpp#L69) [IO-01](3_BUILDING_BLOCKS/01_input_output.cpp#L12) |
| 14 | [**14_class_array_selection_sort.cpp**](2_PRACTICE/14_class_array_selection_sort.cpp)<br>class with a STATIC array of 10 numbers - random fill, display, selection sort ascending AND descending, smallest / largest value (your INF.04 group A: "sortowanie przez wybieranie malejąco + wartość najmniejsza") | [CLS-04](3_BUILDING_BLOCKS/08_classes.cpp#L223) [SORT-03](3_BUILDING_BLOCKS/04_sorting.cpp#L77) [SORT-04](3_BUILDING_BLOCKS/04_sorting.cpp#L105) [ARR-05](3_BUILDING_BLOCKS/03_arrays.cpp#L92) [ARR-06](3_BUILDING_BLOCKS/03_arrays.cpp#L114) [ARR-02](3_BUILDING_BLOCKS/03_arrays.cpp#L32) |
| 15 | [**15_class_object_counter_copy_constructor.cpp**](2_PRACTICE/15_class_object_counter_copy_constructor.cpp)<br>class with a STATIC object counter and automatic id, private fields, getters/setters with validation, copy constructor, array of objects | [CLS-01](3_BUILDING_BLOCKS/08_classes.cpp#L21) [CLS-02](3_BUILDING_BLOCKS/08_classes.cpp#L94) |
| 16 | [**16_inheritance_polymorphism_shapes.cpp**](2_PRACTICE/16_inheritance_polymorphism_shapes.cpp)<br>inheritance + polymorphism - abstract base class Figura, derived Kolo / Prostokat / Trojkat, array of base-class pointers, virtual methods, largest area | [CLS-06](3_BUILDING_BLOCKS/08_classes.cpp#L337) [CLS-05](3_BUILDING_BLOCKS/08_classes.cpp#L284) |

## Task phrase → block

What the sheet says (Polish) → the block to paste.

| The sheet says… | Block |
|---|---|
| "wczytaj liczbę", "sprawdź poprawność danych" | [IO-01](3_BUILDING_BLOCKS/01_input_output.cpp#L12) [IO-02](3_BUILDING_BLOCKS/01_input_output.cpp#L34) [STR-16](3_BUILDING_BLOCKS/06_strings.cpp#L372) |
| "menu", "powtarzaj dopóki" | [IO-05](3_BUILDING_BLOCKS/01_input_output.cpp#L96) [IO-04](3_BUILDING_BLOCKS/01_input_output.cpp#L72) |
| "wypełnij tablicę liczbami pseudolosowymi" | [RND-02](3_BUILDING_BLOCKS/02_random.cpp#L27) |
| "bez powtórzeń", "lotto" | [RND-03](3_BUILDING_BLOCKS/02_random.cpp#L46) |
| "wyświetl w postaci indeks: wartość" | [ARR-01](3_BUILDING_BLOCKS/03_arrays.cpp#L15) |
| "suma", "średnia", "iloczyn" | [ARR-03](3_BUILDING_BLOCKS/03_arrays.cpp#L50) [ARR-04](3_BUILDING_BLOCKS/03_arrays.cpp#L69) [ARR-10](3_BUILDING_BLOCKS/03_arrays.cpp#L208) |
| "wartość najmniejsza / największa", "wartości ekstremalne" | [ARR-05](3_BUILDING_BLOCKS/03_arrays.cpp#L92) [ARR-06](3_BUILDING_BLOCKS/03_arrays.cpp#L114) [ARR-07](3_BUILDING_BLOCKS/03_arrays.cpp#L136) |
| "wyszukaj … zwraca indeks lub -1" | [ARR-13](3_BUILDING_BLOCKS/03_arrays.cpp#L274) [ARR-14](3_BUILDING_BLOCKS/03_arrays.cpp#L296) |
| "wyszukiwanie z wartownikiem" | [ARR-16](3_BUILDING_BLOCKS/03_arrays.cpp#L347) |
| "wyszukiwanie binarne / połówkowe" | [ARR-17](3_BUILDING_BLOCKS/03_arrays.cpp#L373) |
| "podzielne przez k", "ile elementów spełnia" | [ARR-11](3_BUILDING_BLOCKS/03_arrays.cpp#L227) [ARR-12](3_BUILDING_BLOCKS/03_arrays.cpp#L252) |
| "ile razy wystąpiła", "histogram", "kości" | [ARR-15](3_BUILDING_BLOCKS/03_arrays.cpp#L324) [ARR-19](3_BUILDING_BLOCKS/03_arrays.cpp#L425) |
| "sortowanie bąbelkowe" | [SORT-01](3_BUILDING_BLOCKS/04_sorting.cpp#L14) [SORT-02](3_BUILDING_BLOCKS/04_sorting.cpp#L46) |
| "sortowanie przez wybieranie" | [SORT-03](3_BUILDING_BLOCKS/04_sorting.cpp#L77) [SORT-04](3_BUILDING_BLOCKS/04_sorting.cpp#L105) |
| "sortowanie przez wstawianie" | [SORT-05](3_BUILDING_BLOCKS/04_sorting.cpp#L133) |
| "sortowanie szybkie" | [SORT-06](3_BUILDING_BLOCKS/04_sorting.cpp#L158) |
| "liczba pierwsza", "sito Eratostenesa" | [NUM-01](3_BUILDING_BLOCKS/05_numbers.cpp#L15) [NUM-02](3_BUILDING_BLOCKS/05_numbers.cpp#L39) |
| "NWD algorytmem Euklidesa", "NWW" | [NUM-05](3_BUILDING_BLOCKS/05_numbers.cpp#L118) [NUM-04](3_BUILDING_BLOCKS/05_numbers.cpp#L97) [NUM-07](3_BUILDING_BLOCKS/05_numbers.cpp#L170) |
| "silnia", "ciąg Fibonacciego" | [NUM-08](3_BUILDING_BLOCKS/05_numbers.cpp#L184) [NUM-10](3_BUILDING_BLOCKS/05_numbers.cpp#L219) |
| "liczba doskonała", "dzielniki" | [NUM-18](3_BUILDING_BLOCKS/05_numbers.cpp#L389) [NUM-19](3_BUILDING_BLOCKS/05_numbers.cpp#L414) |
| "zamiana na system dwójkowy" | [NUM-24](3_BUILDING_BLOCKS/05_numbers.cpp#L549) |
| "zlicz samogłoski / spółgłoski / cyfry" | [STR-03](3_BUILDING_BLOCKS/06_strings.cpp#L47) [STR-04](3_BUILDING_BLOCKS/06_strings.cpp#L69) [STR-05](3_BUILDING_BLOCKS/06_strings.cpp#L94) |
| "palindrom", "odwróć napis" | [STR-11](3_BUILDING_BLOCKS/06_strings.cpp#L246) [STR-10](3_BUILDING_BLOCKS/06_strings.cpp#L228) |
| "szyfr Cezara", "klucz" | [STR-14](3_BUILDING_BLOCKS/06_strings.cpp#L327) [STR-15](3_BUILDING_BLOCKS/06_strings.cpp#L358) |
| "generator haseł" | [RND-07](3_BUILDING_BLOCKS/02_random.cpp#L126) |
| "PESEL", "cyfra kontrolna", "płeć" | [PESEL-03](3_BUILDING_BLOCKS/07_pesel.cpp#L59) [PESEL-04](3_BUILDING_BLOCKS/07_pesel.cpp#L95) [PESEL-05](3_BUILDING_BLOCKS/07_pesel.cpp#L113) |
| "klasa z polami prywatnymi, konstruktor, metody" | [CLS-01](3_BUILDING_BLOCKS/08_classes.cpp#L21) |
| "klasa z tablicą", "tablica dynamiczna" | [CLS-03](3_BUILDING_BLOCKS/08_classes.cpp#L146) [CLS-04](3_BUILDING_BLOCKS/08_classes.cpp#L223) |
| "licznik obiektów", "pole statyczne" | [CLS-02](3_BUILDING_BLOCKS/08_classes.cpp#L94) |
| "dziedziczenie", "polimorfizm", "klasa abstrakcyjna" | [CLS-05](3_BUILDING_BLOCKS/08_classes.cpp#L284) [CLS-06](3_BUILDING_BLOCKS/08_classes.cpp#L337) |
| "zapisz do pliku", "odczytaj z pliku" | [FILE-01](3_BUILDING_BLOCKS/09_files.cpp#L14) [FILE-03](3_BUILDING_BLOCKS/09_files.cpp#L61) [FILE-04](3_BUILDING_BLOCKS/09_files.cpp#L89) [FILE-05](3_BUILDING_BLOCKS/09_files.cpp#L112) |
| "wyjątek", "obsłuż błąd" | [EXC-03](3_BUILDING_BLOCKS/10_exceptions.cpp#L13) [EXC-05](3_BUILDING_BLOCKS/10_exceptions.cpp#L39) |
| "szablon funkcji / klasy" | [TPL-01](3_BUILDING_BLOCKS/12_templates.cpp#L14) [TPL-03](3_BUILDING_BLOCKS/12_templates.cpp#L52) |

## Building blocks - full catalog

How to paste: copy from the comment box to the end of the code under a `//@` line (stop at the next `//@`). *Needs* = the `#include` it requires.

### Input / output - [01_input_output.cpp](3_BUILDING_BLOCKS/01_input_output.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [IO-01](3_BUILDING_BLOCKS/01_input_output.cpp#L12) | `wczytajLiczbe` | read an int from a range min..max, ask again until it fits (do-while) | &lt;iostream&gt; &lt;string&gt; |
| [IO-02](3_BUILDING_BLOCKS/01_input_output.cpp#L34) | `wczytajLiczbeRzeczywista` | read a real number (double) from a range min..max, ask again until it fits | &lt;iostream&gt; &lt;string&gt; |
| [IO-03](3_BUILDING_BLOCKS/01_input_output.cpp#L56) | `wczytajTekst` | read a whole line of text (with spaces) - after an earlier cin &gt;&gt; call cin.ignore(); first | &lt;iostream&gt; &lt;string&gt; |
| [IO-04](3_BUILDING_BLOCKS/01_input_output.cpp#L72) | `zapytajTakNie` | yes/no question (t/n) -&gt; bool; use as: do { ... } while (zapytajTakNie("Jeszcze raz? (t/n): ")); | &lt;iostream&gt; &lt;string&gt; |
| [IO-05](3_BUILDING_BLOCKS/01_input_output.cpp#L96) | `menu` | menu loop: do-while + switch, ends on 0 (put your function calls in the cases) | &lt;iostream&gt; |
| [IO-07](3_BUILDING_BLOCKS/01_input_output.cpp#L133) | `wypiszLinie` | print a separator line, e.g. ---------- | &lt;iostream&gt; |

### Random numbers - [02_random.cpp](3_BUILDING_BLOCKS/02_random.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [RND-01](3_BUILDING_BLOCKS/02_random.cpp#L13) | `losujLiczbe` | random int from min..max inclusive (rand) - needs srand(time(0)) once in main | &lt;cstdlib&gt; &lt;ctime&gt; |
| [RND-02](3_BUILDING_BLOCKS/02_random.cpp#L27) | `wypelnijLosowo` | fill an array with random ints min..max (e.g. dice 1..6) | &lt;cstdlib&gt; &lt;ctime&gt; |
| [RND-03](3_BUILDING_BLOCKS/02_random.cpp#L46) | `losujBezPowtorzen` | fill an array with random ints WITHOUT repeats (lotto: 6 of 1..49) | &lt;cstdlib&gt; &lt;ctime&gt; |
| [RND-04](3_BUILDING_BLOCKS/02_random.cpp#L78) | `tasujTablice` | shuffle an array randomly (Fisher-Yates, manual swap) | &lt;cstdlib&gt; &lt;ctime&gt; |
| [RND-05](3_BUILDING_BLOCKS/02_random.cpp#L98) | `losujRzeczywista` | random real number from min..max | &lt;cstdlib&gt; &lt;ctime&gt; |
| [RND-06](3_BUILDING_BLOCKS/02_random.cpp#L112) | `losujZnak` | random character from a given set of characters | &lt;cstdlib&gt; &lt;string&gt; |
| [RND-07](3_BUILDING_BLOCKS/02_random.cpp#L126) | `generujHaslo` | password generator: length + options (uppercase, digits, special chars) | &lt;cstdlib&gt; &lt;string&gt; |

### Arrays - [03_arrays.cpp](3_BUILDING_BLOCKS/03_arrays.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [ARR-01](3_BUILDING_BLOCKS/03_arrays.cpp#L15) | `wyswietlTablice` | display every element as "index: value" (exam format) | &lt;iostream&gt; |
| [ARR-02](3_BUILDING_BLOCKS/03_arrays.cpp#L32) | `wyswietlWLinii` | display the array in one line, separated by spaces | &lt;iostream&gt; |
| [ARR-03](3_BUILDING_BLOCKS/03_arrays.cpp#L50) | `suma` | sum of all elements |  |
| [ARR-04](3_BUILDING_BLOCKS/03_arrays.cpp#L69) | `srednia` | average (double - no integer division) |  |
| [ARR-05](3_BUILDING_BLOCKS/03_arrays.cpp#L92) | `minimum` | smallest element (minimum) |  |
| [ARR-06](3_BUILDING_BLOCKS/03_arrays.cpp#L114) | `maksimum` | largest element (maximum) |  |
| [ARR-07](3_BUILDING_BLOCKS/03_arrays.cpp#L136) | `znajdzEkstrema` | min AND max in one pass, "returned" through &amp; parameters ("wartosci ekstremalne") |  |
| [ARR-08](3_BUILDING_BLOCKS/03_arrays.cpp#L164) | `indeksMinimum` | INDEX of the smallest element |  |
| [ARR-09](3_BUILDING_BLOCKS/03_arrays.cpp#L186) | `indeksMaksimum` | INDEX of the largest element |  |
| [ARR-10](3_BUILDING_BLOCKS/03_arrays.cpp#L208) | `iloczyn` | product of all elements (long long - big results) |  |
| [ARR-11](3_BUILDING_BLOCKS/03_arrays.cpp#L227) | `wyswietlPodzielne` | display values divisible by k AND return how many there are (exam wording) | &lt;iostream&gt; |
| [ARR-12](3_BUILDING_BLOCKS/03_arrays.cpp#L252) | `zliczParzyste` | count elements meeting a condition (here: even) - change the if for other conditions |  |
| [ARR-13](3_BUILDING_BLOCKS/03_arrays.cpp#L274) | `wyszukajPierwszy` | linear search: index of the FIRST occurrence or -1 |  |
| [ARR-14](3_BUILDING_BLOCKS/03_arrays.cpp#L296) | `wyszukajWszystkie` | ALL occurrences: writes indexes into indeksy[], returns how many (0 -&gt; print -1) (exam: "zwraca indeksy lub -1") |  |
| [ARR-15](3_BUILDING_BLOCKS/03_arrays.cpp#L324) | `zliczWystapienia` | how many times a value occurs |  |
| [ARR-16](3_BUILDING_BLOCKS/03_arrays.cpp#L347) | `wyszukajZWartownikiem` | SENTINEL search (wartownik): array needs ONE free slot after the data (size n + 1) |  |
| [ARR-17](3_BUILDING_BLOCKS/03_arrays.cpp#L373) | `wyszukajBinarnie` | BINARY search - the array MUST be sorted ascending |  |
| [ARR-18](3_BUILDING_BLOCKS/03_arrays.cpp#L406) | `odwrocTablice` | reverse the array in place (manual swap) |  |
| [ARR-19](3_BUILDING_BLOCKS/03_arrays.cpp#L425) | `zliczKazdaWartosc` | histogram: how many times each value min..max occurs (e.g. dice faces 1..6), prints it | &lt;iostream&gt; |
| [ARR-20](3_BUILDING_BLOCKS/03_arrays.cpp#L453) | `czyPosortowana` | is the array sorted ascending? |  |
| [ARR-21](3_BUILDING_BLOCKS/03_arrays.cpp#L474) | `usunElement` | remove the element at an index (shift left, size decreases) |  |
| [ARR-22](3_BUILDING_BLOCKS/03_arrays.cpp#L497) | `utworzTabliceLosowa` | dynamic array: create with new[] and fill randomly (size given at runtime) - remember delete[] | &lt;cstdlib&gt; &lt;ctime&gt; |
| [ARR-23](3_BUILDING_BLOCKS/03_arrays.cpp#L518) | `wypelnijIWyswietl2D` | 2D array: fill randomly, display as a grid, row sums (fixed number of columns) | &lt;iostream&gt; &lt;cstdlib&gt; |

### Sorting - [04_sorting.cpp](3_BUILDING_BLOCKS/04_sorting.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [SORT-01](3_BUILDING_BLOCKS/04_sorting.cpp#L14) | `sortujBabelkowo` | bubble sort ASCENDING (stops early when nothing was swapped) |  |
| [SORT-02](3_BUILDING_BLOCKS/04_sorting.cpp#L46) | `sortujBabelkowoMalejaco` | bubble sort DESCENDING |  |
| [SORT-03](3_BUILDING_BLOCKS/04_sorting.cpp#L77) | `sortujPrzezWybieranie` | selection sort ASCENDING (find the minimum, put it at position i) |  |
| [SORT-04](3_BUILDING_BLOCKS/04_sorting.cpp#L105) | `sortujPrzezWybieranieMalejaco` | selection sort DESCENDING (find the maximum) |  |
| [SORT-05](3_BUILDING_BLOCKS/04_sorting.cpp#L133) | `sortujPrzezWstawianie` | insertion sort ASCENDING (shift bigger elements right, insert the key) |  |
| [SORT-06](3_BUILDING_BLOCKS/04_sorting.cpp#L158) | `sortujSzybko` | quicksort (fast, recursive) - call: sortujSzybko(tab, 0, n - 1) |  |
| [SORT-07](3_BUILDING_BLOCKS/04_sorting.cpp#L200) | `sortujPrzezZliczanie` | counting sort - for small value ranges (e.g. grades 1..6, dice) |  |

### Number algorithms - [05_numbers.cpp](3_BUILDING_BLOCKS/05_numbers.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [NUM-01](3_BUILDING_BLOCKS/05_numbers.cpp#L15) | `czyPierwsza` | is n a prime number? (checks divisors up to sqrt(n)) |  |
| [NUM-02](3_BUILDING_BLOCKS/05_numbers.cpp#L39) | `sitoEratostenesa` | sieve of Eratosthenes: print all primes &lt;= n (n &lt;= 10000), return how many | &lt;iostream&gt; |
| [NUM-03](3_BUILDING_BLOCKS/05_numbers.cpp#L73) | `wypiszPierwszeWPrzedziale` | print primes in a range a..b (needs NUM-01) | &lt;iostream&gt; |
| [NUM-04](3_BUILDING_BLOCKS/05_numbers.cpp#L97) | `nwd` | NWD (GCD) - Euclid, modulo version (fast) |  |
| [NUM-05](3_BUILDING_BLOCKS/05_numbers.cpp#L118) | `nwdOdejmowanie` | NWD (GCD) - Euclid, SUBTRACTION version (exam classic) |  |
| [NUM-06](3_BUILDING_BLOCKS/05_numbers.cpp#L152) | `nwdRekurencyjnie` | NWD (GCD) - recursive version |  |
| [NUM-07](3_BUILDING_BLOCKS/05_numbers.cpp#L170) | `nww` | NWW (LCM) = a / NWD(a, b) * b (needs NUM-04) |  |
| [NUM-08](3_BUILDING_BLOCKS/05_numbers.cpp#L184) | `silnia` | factorial n! with a loop (long long fits up to 20!) |  |
| [NUM-09](3_BUILDING_BLOCKS/05_numbers.cpp#L202) | `silniaRekurencyjnie` | factorial n! recursive |  |
| [NUM-10](3_BUILDING_BLOCKS/05_numbers.cpp#L219) | `fibonacci` | n-th Fibonacci number with a loop (F0 = 0, F1 = 1) |  |
| [NUM-11](3_BUILDING_BLOCKS/05_numbers.cpp#L240) | `fibonacciRekurencyjnie` | n-th Fibonacci number recursive (slow for n &gt; 35) |  |
| [NUM-12](3_BUILDING_BLOCKS/05_numbers.cpp#L257) | `wypiszCiagFibonacciego` | print the first n Fibonacci numbers | &lt;iostream&gt; |
| [NUM-13](3_BUILDING_BLOCKS/05_numbers.cpp#L279) | `sumaCyfr` | sum of the digits of a number |  |
| [NUM-14](3_BUILDING_BLOCKS/05_numbers.cpp#L302) | `liczbaCyfr` | how many digits a number has |  |
| [NUM-15](3_BUILDING_BLOCKS/05_numbers.cpp#L329) | `odwrocLiczbe` | reverse the digits: 1230 -&gt; 321 |  |
| [NUM-16](3_BUILDING_BLOCKS/05_numbers.cpp#L348) | `czyPalindromLiczbowy` | is the number a palindrome (12321)? |  |
| [NUM-17](3_BUILDING_BLOCKS/05_numbers.cpp#L368) | `sumaDzielnikow` | sum of proper divisors (without the number itself) |  |
| [NUM-18](3_BUILDING_BLOCKS/05_numbers.cpp#L389) | `czyDoskonala` | is it a perfect number (6 = 1+2+3, 28, 496)? |  |
| [NUM-19](3_BUILDING_BLOCKS/05_numbers.cpp#L414) | `wypiszDzielniki` | print all divisors of n | &lt;iostream&gt; |
| [NUM-20](3_BUILDING_BLOCKS/05_numbers.cpp#L437) | `rozkladNaCzynniki` | prime factorization: 360 = 2 * 2 * 2 * 3 * 3 * 5 | &lt;iostream&gt; |
| [NUM-21](3_BUILDING_BLOCKS/05_numbers.cpp#L473) | `potega` | power a^b, fast (squaring), integers |  |
| [NUM-22](3_BUILDING_BLOCKS/05_numbers.cpp#L497) | `czyArmstronga` | Armstrong / narcissistic number (153 = 1^3 + 5^3 + 3^3) |  |
| [NUM-23](3_BUILDING_BLOCKS/05_numbers.cpp#L532) | `czyPrzestepny` | leap year? |  |
| [NUM-24](3_BUILDING_BLOCKS/05_numbers.cpp#L549) | `naSystem` | decimal -&gt; any base 2..16 (binary, octal, hex) as text (each new digit goes in front) | &lt;string&gt; |
| [NUM-25](3_BUILDING_BLOCKS/05_numbers.cpp#L575) | `zSystemu` | any base 2..16 -&gt; decimal (Horner's scheme) | &lt;string&gt; &lt;cctype&gt; |
| [NUM-26](3_BUILDING_BLOCKS/05_numbers.cpp#L605) | `zaokraglij` | round to k decimal places (e.g. 3.14159 -&gt; 3.14) | &lt;cmath&gt; |

### Strings - [06_strings.cpp](3_BUILDING_BLOCKS/06_strings.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [STR-01](3_BUILDING_BLOCKS/06_strings.cpp#L13) | `naWielkie` | text to UPPER case | &lt;string&gt; &lt;cctype&gt; |
| [STR-02](3_BUILDING_BLOCKS/06_strings.cpp#L30) | `naMale` | text to lower case | &lt;string&gt; &lt;cctype&gt; |
| [STR-03](3_BUILDING_BLOCKS/06_strings.cpp#L47) | `zliczSamogloski` | count vowels (a e i o u y, any case) | &lt;string&gt; &lt;cctype&gt; |
| [STR-04](3_BUILDING_BLOCKS/06_strings.cpp#L69) | `zliczSpolgloski` | count consonants (letters that are not vowels) | &lt;string&gt; &lt;cctype&gt; |
| [STR-05](3_BUILDING_BLOCKS/06_strings.cpp#L94) | `zliczCyfry` | count digits in a text | &lt;string&gt; &lt;cctype&gt; |
| [STR-06](3_BUILDING_BLOCKS/06_strings.cpp#L115) | `zliczZnak` | count occurrences of one character | &lt;string&gt; |
| [STR-07](3_BUILDING_BLOCKS/06_strings.cpp#L137) | `zliczSlowa` | count words separated by spaces (counts where a word starts) | &lt;string&gt; |
| [STR-08](3_BUILDING_BLOCKS/06_strings.cpp#L159) | `podzielNaSlowa` | split a text into words -&gt; string slowa[] array, returns how many | &lt;string&gt; |
| [STR-09](3_BUILDING_BLOCKS/06_strings.cpp#L196) | `podzielWgSeparatora` | split by a separator, e.g. "Jan;17;4.5" by ';' -&gt; string czesci[] array, returns how many | &lt;string&gt; |
| [STR-10](3_BUILDING_BLOCKS/06_strings.cpp#L228) | `odwrocNapis` | reverse a text | &lt;string&gt; |
| [STR-11](3_BUILDING_BLOCKS/06_strings.cpp#L246) | `czyPalindrom` | palindrome check, ignoring spaces and letter case ("Kobyla ma maly bok") | &lt;string&gt; &lt;cctype&gt; |
| [STR-12](3_BUILDING_BLOCKS/06_strings.cpp#L276) | `usunSpacje` | remove all spaces | &lt;string&gt; |
| [STR-13](3_BUILDING_BLOCKS/06_strings.cpp#L297) | `zamienWszystkie` | replace ALL occurrences of a fragment with another (walks the text, compares with substr) | &lt;string&gt; |
| [STR-14](3_BUILDING_BLOCKS/06_strings.cpp#L327) | `szyfrujCezarem` | Caesar cipher with any key (keeps case, other chars unchanged); decrypt = key 26 - k | &lt;string&gt; |
| [STR-15](3_BUILDING_BLOCKS/06_strings.cpp#L358) | `deszyfrujCezarem` | Caesar decrypt (needs STR-14) | &lt;string&gt; |
| [STR-16](3_BUILDING_BLOCKS/06_strings.cpp#L372) | `czyLiczbaCalkowita` | is the text a whole number ("123", "-45")? - check BEFORE stoi | &lt;string&gt; &lt;cctype&gt; |
| [STR-17](3_BUILDING_BLOCKS/06_strings.cpp#L401) | `kazdeSlowoWielka` | capitalize every word: "jan kowalski" -&gt; "Jan Kowalski" | &lt;string&gt; &lt;cctype&gt; |
| [STR-18](3_BUILDING_BLOCKS/06_strings.cpp#L425) | `inicjaly` | initials: "Jan Maria Rokita" -&gt; "JMR" | &lt;string&gt; &lt;cctype&gt; |
| [STR-19](3_BUILDING_BLOCKS/06_strings.cpp#L446) | `zamienSlowa` | swap the two words of a 2-word text: "Jan Kowalski" -&gt; "Kowalski Jan" | &lt;string&gt; |
| [STR-20](3_BUILDING_BLOCKS/06_strings.cpp#L474) | `czestoscLiter` | frequency of each letter a..z (prints only the letters that occur) | &lt;iostream&gt; &lt;string&gt; &lt;cctype&gt; |
| [STR-21](3_BUILDING_BLOCKS/06_strings.cpp#L502) | `czyAnagram` | anagram check (same letters, other order: "listen" / "silent") - letter-count arrays | &lt;string&gt; &lt;cctype&gt; |
| [STR-22](3_BUILDING_BLOCKS/06_strings.cpp#L542) | `zliczWielkieIMale` | count upper and lower case letters (results through &amp; parameters) | &lt;string&gt; &lt;cctype&gt; |

### PESEL - [07_pesel.cpp](3_BUILDING_BLOCKS/07_pesel.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [PESEL-01](3_BUILDING_BLOCKS/07_pesel.cpp#L16) | `czyPoprawnyFormatPesel` | is it exactly 11 digits? | &lt;string&gt; &lt;cctype&gt; |
| [PESEL-02](3_BUILDING_BLOCKS/07_pesel.cpp#L40) | `cyfraKontrolnaPesel` | compute the control digit from the first 10 digits | &lt;string&gt; |
| [PESEL-03](3_BUILDING_BLOCKS/07_pesel.cpp#L59) | `czyPoprawnyPesel` | full validation: format + checksum (self-contained) | &lt;string&gt; &lt;cctype&gt; |
| [PESEL-04](3_BUILDING_BLOCKS/07_pesel.cpp#L95) | `plecZPesel` | sex from PESEL: 'K' (woman) or 'M' (man) | &lt;string&gt; |
| [PESEL-05](3_BUILDING_BLOCKS/07_pesel.cpp#L113) | `dataUrodzeniaZPesel` | birth date from PESEL (day, month, year through &amp; parameters, all centuries) | &lt;string&gt; |

### Classes - [08_classes.cpp](3_BUILDING_BLOCKS/08_classes.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [CLS-01](3_BUILDING_BLOCKS/08_classes.cpp#L21) | `Osoba` | basic class: private fields, default + parameter constructor, getters, setters with validation, display | &lt;iostream&gt; &lt;string&gt; |
| [CLS-02](3_BUILDING_BLOCKS/08_classes.cpp#L94) | `Notatka` | static counter of created objects + automatic id (id = 1, 2, 3 ...) | &lt;iostream&gt; &lt;string&gt; |
| [CLS-03](3_BUILDING_BLOCKS/08_classes.cpp#L146) | `Tablica` | class with a DYNAMIC array: size in constructor, random fill 1..6, destructor; add methods from 03_arrays.cpp | &lt;iostream&gt; &lt;cstdlib&gt; &lt;ctime&gt; |
| [CLS-04](3_BUILDING_BLOCKS/08_classes.cpp#L223) | `TablicaStala` | class with a STATIC array of fixed size (const ROZMIAR) - fill, display, find max | &lt;iostream&gt; &lt;cstdlib&gt; &lt;ctime&gt; |
| [CLS-05](3_BUILDING_BLOCKS/08_classes.cpp#L284) | `Pojazd`, `Samochod` | inheritance: base class with protected fields, derived class calls the BASE constructor, virtual method | &lt;iostream&gt; &lt;string&gt; |
| [CLS-06](3_BUILDING_BLOCKS/08_classes.cpp#L337) | `Figura`, `Kolo`, `Prostokat` | abstract base class (pure virtual = 0) + 2 derived classes + polymorphism through an array of Figura* | &lt;iostream&gt; &lt;string&gt; |
| [CLS-07](3_BUILDING_BLOCKS/08_classes.cpp#L416) | `Punkt` | operators for your class: + (member), == (member), &lt;&lt; (friend, for cout) | &lt;iostream&gt; |
| [CLS-08](3_BUILDING_BLOCKS/08_classes.cpp#L464) | `Uczen`, `wyswietlUczniow`, `najlepszyUczen` | struct + array of structs: display all, find the best by a field | &lt;iostream&gt; &lt;string&gt; |

### Files - [09_files.cpp](3_BUILDING_BLOCKS/09_files.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [FILE-01](3_BUILDING_BLOCKS/09_files.cpp#L14) | `zapiszDoPliku` | write an array to a text file (overwrites), numbers separated by spaces | &lt;fstream&gt; &lt;string&gt; |
| [FILE-02](3_BUILDING_BLOCKS/09_files.cpp#L40) | `dopiszDoPliku` | append one line at the END of a file (ios::app) | &lt;fstream&gt; &lt;string&gt; |
| [FILE-03](3_BUILDING_BLOCKS/09_files.cpp#L61) | `wczytajLiczbyZPliku` | read ALL numbers from a file into an int array, returns how many (loop: while (plik &gt;&gt; x)) | &lt;iostream&gt; &lt;fstream&gt; &lt;string&gt; |
| [FILE-04](3_BUILDING_BLOCKS/09_files.cpp#L89) | `wczytajLinieZPliku` | read a file line by line into a string array, returns how many lines | &lt;fstream&gt; &lt;string&gt; |
| [FILE-05](3_BUILDING_BLOCKS/09_files.cpp#L112) | `Rekord`, `wczytajRekordy` | read records "name;age;grade" (one per line) into an array of structs - getline(plik, pole, ';') | &lt;fstream&gt; &lt;string&gt; |
| [FILE-06](3_BUILDING_BLOCKS/09_files.cpp#L156) | `czyPlikIstnieje` | does a file exist (can it be opened)? | &lt;fstream&gt; &lt;string&gt; |

### Exceptions - [10_exceptions.cpp](3_BUILDING_BLOCKS/10_exceptions.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [EXC-03](3_BUILDING_BLOCKS/10_exceptions.cpp#L13) | `podziel` | function that THROWS runtime_error on bad input (division by zero) + try/catch | &lt;iostream&gt; &lt;stdexcept&gt; |
| [EXC-05](3_BUILDING_BLOCKS/10_exceptions.cpp#L39) | `sprawdzWiek` | throw an int or a string, catch each type in its own catch, catch (...) last | &lt;iostream&gt; &lt;string&gt; |

### vector - [11_vector.cpp](3_BUILDING_BLOCKS/11_vector.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [VEC-01](3_BUILDING_BLOCKS/11_vector.cpp#L14) | `wypelnijWektor` | fill a vector with n random ints min..max with push_back (vector passed by reference!) | &lt;vector&gt; &lt;cstdlib&gt; &lt;ctime&gt; |
| [VEC-02](3_BUILDING_BLOCKS/11_vector.cpp#L34) | `wyswietlWektor` | display a vector in one line (index loop up to v.size()) | &lt;iostream&gt; &lt;vector&gt; |
| [VEC-03](3_BUILDING_BLOCKS/11_vector.cpp#L51) | `statystykiWektora` | min, max, sum, average of a vector with one own loop (prints them) | &lt;iostream&gt; &lt;vector&gt; |

### Templates - [12_templates.cpp](3_BUILDING_BLOCKS/12_templates.cpp)

| ID | Name | What it does | Needs |
|---|---|---|---|
| [TPL-01](3_BUILDING_BLOCKS/12_templates.cpp#L14) | `wiekszy` | function template: larger of two values of ANY type |  |
| [TPL-02](3_BUILDING_BLOCKS/12_templates.cpp#L33) | `wyswietlDowolna` | function template: display an array of ANY type | &lt;iostream&gt; |
| [TPL-03](3_BUILDING_BLOCKS/12_templates.cpp#L52) | `Para` | class template with TWO type parameters: constructor, getters, display | &lt;iostream&gt; |
| [TPL-04](3_BUILDING_BLOCKS/12_templates.cpp#L92) | `oblicz` | function template + a full SPECIALIZATION for &lt;int, float&gt;; other types = instantiation | &lt;iostream&gt; |

## More

* [4_NOTES](4_NOTES/README.md) - learning material by topic · [00_start_here](4_NOTES/00_start_here/README.md) - compiling, running, compiler errors decoded
* [4_NOTES/original_files_map.md](4_NOTES/original_files_map.md) - where every file from the original repo (`C---main.zip`) ended up
* Build: `g++ -std=c++17 file.cpp -o program.exe` · VS Code: **Ctrl+Shift+B** builds the open file
