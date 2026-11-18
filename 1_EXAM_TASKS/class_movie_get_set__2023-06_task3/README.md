# INF.04-03-23.06-SG (= INF.04-01-23.06-SD) – Klasa film (get, set, inkrementuj)

[⬅ all tasks](../README.md) · Sheet: [2023-06 task 3 SG](exam_sheet_2023-06_task3_SG.pdf), [2023-06 task 1 SD](exam_sheet_2023-06_task1_SD.pdf) · Key: [2023-06 task 3 SG](grading_key_2023-06_task3_SG.xlsx), [2023-06 task 1 SD](grading_key_2023-06_task1_SD.xlsx)

**Files:** main.cpp · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsola`, `web`, `dokumentacja`. Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- fields title (≤ 20 chars) and rentals count; access: class **and derived classes** → `protected`
- init: empty / 0; setter of title; getters of title and count; `inkrementuj()` without args, void
- main: show fields after init, test set, test get, count before and after inkrementuj

## Key checks
- [ ] two protected fields
- [ ] initialisation to "" / 0
- [ ] set, 2× get, parameterless void increment
- [ ] all four tests visible in the output
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
class header: nazwa klasy / pola / metody (name, return, description) / informacje / autor. Replace `00000000000` with **your exam number**.

## Related building blocks
`CLS-01` – see the [catalog](../../README.md#building-blocks---full-catalog)
