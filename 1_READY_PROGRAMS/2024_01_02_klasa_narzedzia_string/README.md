# INF.04-02-24.01-SG (+ 24.01-02-AG, 24.06-01-SD) – Klasa narzędzi dla napisów (samogłoski, powtórzenia)

[⬅ all tasks](../README.md) · Sheet: [2024_01_02_SG](../../4_ARKUSZE/inf_04_2024_01_02_SG.pdf), [2024_01_02_AG](../../4_ARKUSZE/inf_04_2024_01_02_AG.pdf), [2024_06_01_SD](../../4_ARKUSZE/inf_04_2024_06_01_SD.pdf) · Key: [2024_01_02_SG_zo](../../4_ARKUSZE/klucze/INF_04_2024_01_02_SG_zo.pdf), [2024_06_01_SD_zo](../../4_ARKUSZE/klucze/INF_04_2024_06_01_SD_zo.pdf)

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
Polish letters (ą, ę, ó) are typed by the user, so this program uses **wide strings** (`wstring`, `wcin`/`wcout` in UTF-16 mode). The file is saved as **UTF-8 with BOM**, so Visual Studio reads `L"ą"` correctly. `const wchar_t*` parameters make the null case real.

## Related building blocks
`STR-03` · `STR-12` – see the [catalog](../../README.md#building-blocks---full-catalog)
