# INF.04-02-26.06-SG – Klasa Notatka z datą dodania

[⬅ all tasks](../README.md) · Sheet: [2026_06_02_SG](../../4_ARKUSZE/inf_04_2026_06_02_SG.pdf) · Key: [2026_06_02_SG_zo](../../4_ARKUSZE/klucze/INF_04_2026_06_02_SG_zo.pdf)

**Files:** main.cpp · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsolowa`, `mobilna`, `dokumentacja`. Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- **public** fields: title, content (strings), priority (bool), date added (date type: `time_t`)
- constructor(title, content, priority) and constructor(title): content "", not important; both set the date to **now**
- `wypisz()`: line of underscores, "Notatka WAŻNA! <tytuł>" or "Notatka <tytuł>", content, date, line
- main: important note with data in the code + note with the title from the keyboard, then show both

## Key checks
- [ ] 4 public fields with the right types
- [ ] two constructors (3 and 1 argument), current date
- [ ] display method in the exact format
- [ ] main as described
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
header of the method (here `wypisz`): nazwa / opis / parametry / zwracany typ / autor. Replace `00000000000` with **your exam number**.

## Related building blocks
`CLS-01` – see the [catalog](../../README.md#building-blocks---full-catalog)
