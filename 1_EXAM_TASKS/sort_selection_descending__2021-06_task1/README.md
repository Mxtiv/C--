# INF.04-01-21.06-SG (= INF.04-01-22.01-SG) – Sortowanie przez wybieranie (malejąco, klasa)

[⬅ all tasks](../README.md) · Sheet: [2021-06 task 1 SG](exam_sheet_2021-06_task1_SG.pdf), [2022-01 task 1 SG](exam_sheet_2022-01_task1_SG.pdf) · Key: [2021-06 task 1 SG](grading_key_2021-06_task1_SG.pdf), [2022-01 task 1 SG](grading_key_2022-01_task1_SG.pdf)

**Files:** main.cpp · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsola`, `mobilna`, `dokumentacja` (screenshot `konsola.jpg`). Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- class with a field `int tablica[10]`, read from the keyboard after a prompt
- selection sort **descending**: no ready sort / max functions
- at least 2 methods: sorting and searching the max; the search method is **private**, returns the max or its index
- display the sorted array

## Key checks
- [ ] class with a 10-element int array field + ≥ 2 methods, search method private/protected
- [ ] search returns the max value or its index
- [ ] selection-sort idea (find max from i to the end, swap with i)
- [ ] a loop over the array
- [ ] output in descending order
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
`/****` header above **sortuj and szukajMaksimum**: nazwa funkcji / parametry wejściowe / wartość zwracana / autor (2021 pattern). Replace `00000000000` with **your exam number**.

## Related building blocks
`SORT-04` · `CLS-04` · `ARR-09` – see the [catalog](../../README.md#building-blocks---full-catalog)
