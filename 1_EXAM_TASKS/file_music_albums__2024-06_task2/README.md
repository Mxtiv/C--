# INF.04-02-24.06-SG – Albumy muzyczne z pliku (Data.txt)

[⬅ all tasks](../README.md) · Sheet: [2024-06 task 2 SG](exam_sheet_2024-06_task2_SG.pdf) · Key: [2024-06 task 2 SG](grading_key_2024-06_task2_SG.pdf)

**Files:** main.cpp, Data.txt, DataStructure.txt · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsolowa`, `desktopowa`, `dokumentacja` (archive `pliki2.zip`, password `My^SoUndS`). Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- struct/class: **2 strings + 3 ints** (artist, album, songs, year, downloads ≥ 32 bit)
- read ALL records of Data.txt (5 lines + empty line each; any number of records) in a separate function
- records stored in an array/collection; display them in a separate function, one value per line

## Key checks
- [ ] struct/class with 2 string + 3 integer fields
- [ ] file read with the language's proper technique and closed
- [ ] reading in a loop, works for any number of records
- [ ] fields filled in order: artist, album, songs, year, downloads
- [ ] **1506404300** shown correctly (not cut / negative)
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
header of a chosen function: nazwa funkcji / opis funkcji / parametry / zwracany typ i opis / autor. Replace `00000000000` with **your exam number**.

## Notes
`Data.txt` must be in the working folder. In Visual Studio that is the project folder, next to the `.vcxproj`; with g++ it is the folder you run from. Records go into a plain array `Album albumy[100]`; the read function returns how many it read. Downloads are an `int` (32 bit, enough for 1506404300). The reader strips the UTF-8 BOM and the `\r` of Windows line ends.

## Related building blocks
`FILE-04` · `CLS-08` – see the [catalog](../../README.md#building-blocks---full-catalog)
