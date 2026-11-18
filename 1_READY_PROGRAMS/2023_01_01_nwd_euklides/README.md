# INF.04-01-23.01-SG (+ AG) – NWD – algorytm Euklidesa

[⬅ all tasks](../README.md) · Sheet: [2023_01_01_SG_kolor](../../4_ARKUSZE/inf_04_2023_01_01_SG_kolor.pdf), [2023_01_01_AG_kolor](../../4_ARKUSZE/inf_04_2023_01_01_AG_kolor.pdf) · Key: [2023_01_01_SG_zo_punktacja](../../4_ARKUSZE/klucze/INF_04_2023_01_01_SG_zo_punktacja.xlsx)

**Files:** main.cpp · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsola`, `desktopowa`, `dokumentacja`. Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- Euclid **exactly as in the flowchart**: `while (a != b)` → `if (a > b) a = a - b; else b = b - a;`
- a, b positive integers (type or input check)
- function with 2 arguments returning the GCD, **no input/output inside**
- main reads the numbers and shows the result; variable names a, b as in the flowchart

## Key checks
- [ ] while/do-while running while a ≠ b
- [ ] inside: compare a and b, subtract the smaller from the bigger
- [ ] two numbers read in main
- [ ] meaningful function name
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
header above **nwd**: nazwa funkcji / opis funkcji / parametry / zwracany typ i opis / autor. Replace `00000000000` with **your exam number**.

## Related building blocks
`NUM-05` · `IO-01` – see the [catalog](../../README.md#building-blocks---full-catalog)
