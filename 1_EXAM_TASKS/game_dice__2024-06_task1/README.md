# INF.04-01-24.06-SG (= INF.04-01-25.01-SD) – Gra w kości

[⬅ all tasks](../README.md) · Sheet: [2024-06 task 1 SG](exam_sheet_2024-06_task1_SG.pdf), [2025-01 task 1 SD](exam_sheet_2025-01_task1_SD.pdf) · Key: [2024-06 task 1 SG](grading_key_2024-06_task1_SG.pdf), [2025-01 task 1 SD](grading_key_2025-01_task1_SD.pdf)

**Files:** main.cpp · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsolowa`, `mobilna`, `dokumentacja`. Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- ask for the number of dice until it is in **3..10**
- roll: random 1..6 into an array (function with parameters, no globals)
- print "Kostka <n>: <oczka>"
- points = sum of the values rolled **at least twice** (1,5,2,2,5 → 14; 2,1,2,3,2 → 6), returned by a function
- "t" → roll again, "n" → end

## Key checks
- [ ] main + roll function + points function; int array with 1..6
- [ ] points function returns an int
- [ ] fill and display with loops of the right length
- [ ] a loop for the dice count / play-again question
- [ ] boundaries: 2 and 11 rejected, 3 and 10 accepted
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
header of a chosen function: nazwa / opis / parametry / zwracany typ i opis / autor. Replace `00000000000` with **your exam number**.

## Related building blocks
`RND-02` · `ARR-19` · `IO-04` – see the [catalog](../../README.md#building-blocks---full-catalog)
