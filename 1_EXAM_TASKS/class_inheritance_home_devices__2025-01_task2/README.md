# INF.04-02-25.01-SG (= INF.04-01-25.06-SD) – Urządzenia domowe – dziedziczenie (pralka, odkurzacz)

[⬅ all tasks](../README.md) · Sheet: [2025-01 task 2 SG](exam_sheet_2025-01_task2_SG.pdf), [2025-06 task 1 SD](exam_sheet_2025-06_task1_SD.pdf) · Key: [2025-01 task 2 SG](grading_key_2025-01_task2_SG.pdf), [2025-06 task 1 SD](grading_key_2025-06_task1_SD.pdf)

**Files:** main.cpp · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsolowa`, `mobilna`, `dokumentacja`. Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- base class: public method showing the message given as argument, void
- Pralka: **private** program number = 0; public method sets 1..12 (otherwise 0) and **returns** the field
- Odkurzacz: **private** bool = false; `on()` / `off()` change the state and call the base method ("Odkurzacz włączono" / "wyłączono") **only when the state really changes**
- main: washing machine with a correct and a wrong number (messages), vacuum: on() ×3 (one message), base method "Odkurzacz wyładował się", off()

## Key checks
- [ ] 3 classes, 1 base + 2 derived; objects of both derived classes in main
- [ ] base method public, void, message argument
- [ ] private int = 0 and private bool = false
- [ ] set method 1..12 else 0, returns the field
- [ ] on/off public, void, guarded by the state
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
header of the **base class method**: nazwa / opis / parametry / zwracany typ i opis / autor. Replace `00000000000` with **your exam number**.

## Related building blocks
`CLS-05` – see the [catalog](../../README.md#building-blocks---full-catalog)
