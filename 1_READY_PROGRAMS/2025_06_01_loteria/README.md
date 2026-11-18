# INF.04-01-25.06-SG (+ AG) – Loteria – zestawy 6 liczb z 49

[⬅ all tasks](../README.md) · Sheet: [2025_06_01_SG](../../4_ARKUSZE/inf_04_2025_06_01_SG.pdf), [2025_06_01_AG](../../4_ARKUSZE/inf_04_2025_06_01_AG.pdf) · Key: [2025_06_01_SG_zo](../../4_ARKUSZE/klucze/INF_04_2025_06_01_SG_zo.pdf), [2025_06_01_AG_zo](../../4_ARKUSZE/klucze/INF_04_2025_06_01_AG_zo.pdf)

**Files:** main.cpp · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsolowa`, `desktopowa`, `dokumentacja`. Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- read n = number of sets
- each set: 6 **different** random numbers from 1..49
- store in a **2D array n × 6** (here a plain `int zestawy[100][6]`; n is read from the keyboard in a do-while loop until it is 1..100, only the first n rows are used)
- at least 2 functions: fill, display (no globals)
- count how many times each number 1..49 appears in all sets and display it

## Key checks
- [ ] main + ≥ 2 functions; data not lost after the fill function
- [ ] 2D array / dynamic collection
- [ ] pseudo-random generator, range 1..49
- [ ] no repeats inside one set
- [ ] occurrences of 1..49 displayed
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
header of any function: nazwa funkcji / opis funkcji / parametry / zwracany typ i opis / autor. Replace `00000000000` with **your exam number**.

## Related building blocks
`RND-03` · `ARR-23` · `ARR-19` – see the [catalog](../../README.md#building-blocks---full-catalog)
