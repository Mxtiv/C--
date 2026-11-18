# INF.04-02-22.06-SG – Klasa Osoba (forum, pole statyczne)

[⬅ all tasks](../README.md) · Sheet: [2022-06 task 2 SG](exam_sheet_2022-06_task2_SG.pdf) · Key: [2022-06 task 2 SG](grading_key_2022-06_task2_SG.xlsx)

**Files:** main.cpp · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsola`, `web`, `testy` (screenshots + egzamin go to **testy**). Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- class Osoba: `id` and `imie` **private**; public **static** instance counter = 0
- 3 constructors (none → 0 / "", two params, **copy**), each increments the counter
- method: "Cześć <argument>, mam na imię <imie>", or "Brak danych" when the name is empty
- main (part III, in this order): show the counter → default object → object with data from the keyboard → copy of it → the method with "Jan" for all → show the counter again

## Key checks
- [ ] two private fields, public static counter starting at 0
- [ ] three constructors incl. copy; each increments the counter
- [ ] method prints the greeting / "Brak danych"
- [ ] main performs the tests in the given order
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
class header: nazwa klasy / pola / metody / informacje / autor. Replace `00000000000` with **your exam number**.

## Related building blocks
`CLS-02` · `CLS-01` – see the [catalog](../../README.md#building-blocks---full-catalog)
