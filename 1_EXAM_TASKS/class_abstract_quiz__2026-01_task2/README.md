# INF.04-02-26.01-SG – Quiz – klasa abstrakcyjna Pytanie + PytanieZamkniete

[⬅ all tasks](../README.md) · Sheet: [2026-01 task 2 SG](exam_sheet_2026-01_task2_SG.pdf) · Key: [2026-01 task 2 SG](grading_key_2026-01_task2_SG.pdf)

**Files:** main.cpp · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsolowa`, `mobilna`, `dokumentacja` (test1.png, test2.png, git1.png…). Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- **Pytanie**: no objects allowed (abstract). **Protected** fields: question text, image file name, bool "correct". Constructor(text, file) sets them and correct = false. **Pure virtual** `bool sprawdzOdpowiedz(char)` (A/B/C)
- **PytanieZamkniete : Pytanie**: **private** answers A, B, C + correct letter. 6-argument constructor calls the base constructor. The check sets the bool field and returns it
- part III: try to create a `Pytanie` object, then screenshot the compile error (**test1.png**) and comment that code out
- main: data for the constructor + the answer from the keyboard → "Odpowiedź prawidłowa" / "Odpowiedź nieprawidłowa" (**test2.png**)
- part III also wants **Git**: list all commits with messages + user config (screenshots git1.png…)

## Key checks
- [ ] abstract base with protected fields and a pure virtual method
- [ ] derived class with private fields, constructor calling the base one
- [ ] implementation sets the bool and returns it
- [ ] test1 (error) and test2 (result) screenshots
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
header of a method (here `sprawdzOdpowiedz`): nazwa / opis / parametry / zwracany typ i opis / autor. Replace `00000000000` with **your exam number**.

## Notes
**Git for part III** (in the project folder):
```
git init
git config user.name "<numer>"
git config user.email "egzamin@poczta.pl"
git add .
git commit -m "Klasy Pytanie i PytanieZamkniete"
... more work, more commits ...
git log            (all commits with messages)
git config --list  (shows user.name and user.email) -> screenshots git1.png, git2.png
```

## Related building blocks
`CLS-06` · `CLS-05` – see the [catalog](../../README.md#building-blocks---full-catalog)
