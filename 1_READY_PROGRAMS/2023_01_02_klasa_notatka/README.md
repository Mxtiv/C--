# INF.04-02-23.01-SG (+ 23.01-01-SD, 23.01-02-AG) – Klasa notatka (licznik statyczny)

[⬅ all tasks](../README.md) · Sheet: [2023_01_02_SG_kolor](../../4_ARKUSZE/inf_04_2023_01_02_SG_kolor.pdf), [2023_01_01_SD_kolor](../../4_ARKUSZE/inf_04_2023_01_01_SD_kolor.pdf), [2023_01_02_AG_kolor](../../4_ARKUSZE/inf_04_2023_01_02_AG_kolor.pdf) · Key: [2023_01_02_SG_zo](../../4_ARKUSZE/klucze/INF_04_2023_01_02_SG_zo.xlsx), [2023_01_01_SD_zo](../../4_ARKUSZE/klucze/INF_04_2023_01_01_SD_zo.xlsx)

**Files:** main.cpp · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsola`, `mobilna`, `dokumentacja`. Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- fields: static counter + id → **private**; title + content → **protected**
- one constructor (title, content): counter++ **first**, then id = counter, then the texts
- two public void methods without parameters: show title + content; diagnostic: all fields separated by **";"**
- main: two notes with meaningful data, both methods on each

## Key checks
- [ ] two numeric private + two text protected fields
- [ ] counter static, incremented BEFORE assigning id
- [ ] constructor with 2 string params
- [ ] two public parameterless void methods; one shows only title+content, the other all fields with ";"
- [ ] two objects created and both methods called
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
class header: klasa / opis / pola (all of them) / autor. Replace `00000000000` with **your exam number**.

## Related building blocks
`CLS-02` · `CLS-01` – see the [catalog](../../README.md#building-blocks---full-catalog)
