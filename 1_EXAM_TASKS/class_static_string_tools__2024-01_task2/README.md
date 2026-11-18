# INF.04-02-24.01-SG (+ 24.01-02-AG, 24.01-01-SD, 24.06-01-SD) – Klasa narzędzi dla napisów (samogłoski, powtórzenia)

[⬅ all tasks](../README.md) · Sheet: [2024-01 task 2 SG](exam_sheet_2024-01_task2_SG.pdf), [2024-01 task 1 SD](exam_sheet_2024-01_task1_SD.pdf), [2024-01 task 2 AG](exam_sheet_2024-01_task2_AG.pdf), [2024-06 task 1 SD](exam_sheet_2024-06_task1_SD.pdf) · Key: [2024-01 task 2 SG](grading_key_2024-01_task2_SG.pdf), [2024-01 task 1 SD](grading_key_2024-01_task1_SD.pdf), [2024-01 task 2 AG](grading_key_2024-01_task2_AG.pdf), [2024-06 task 1 SD](grading_key_2024-06_task1_SD.pdf)

**Files:** main.cpp · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsola`, `mobilna`, `dokumentacja`. Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- utility class: **all methods static and public**, no objects
- count vowels **"aąeęiouóyAĄEĘIOUÓY"**; empty or null → 0
- remove repeated neighbouring characters ("Abba;;;to zespół" → "Aba;to zespół"); empty/null → ""
- main: read a line from the keyboard, show the vowel count and the cleaned text

## Key checks
- [ ] static public methods
- [ ] vowel method: string parameter, returns int, `return` on every path, null/empty → 0, no index out of range
- [ ] duplicates method: returns a string, null/empty → "", no index out of range
- [ ] counts Polish vowels too
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
class header: klasa / opis / metody (what each returns) / autor. Replace `00000000000` with **your exam number**.

## Notes
Plain `string` + `getline(cin, ...)` + two loops; nothing else needed. A C++ `string` can never be null, so `tekst.empty()` covers both "empty or null" (say so in a comment, the grader looks for the check). `setlocale(LC_ALL, "")` is the usual line for Polish letters in the Visual Studio console; whether typed ą/ę/ó are counted depends on the console encoding, but the grader checks that the vowel list in the code contains them.

## Related building blocks
`STR-03` · `STR-12` – see the [catalog](../../README.md#building-blocks---full-catalog)
