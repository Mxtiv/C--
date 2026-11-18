# INF.04-02-25.06-SG – Szyfr Cezara + testy jednostkowe (Visual Studio)

[⬅ all tasks](../README.md) · Sheet: [2025_06_02_SG](../../4_ARKUSZE/inf_04_2025_06_02_SG.pdf) · Key: [2025_06_02_SG_zo](../../4_ARKUSZE/klucze/INF_04_2025_06_02_SG_zo.pdf)

**Files:** SzyfrCezara.sln, SzyfrCezara/ (main.cpp, szyfr.h, szyfr.cpp), SzyfrCezaraTesty/ (testy.cpp) · **Run:** Open **`SzyfrCezara.sln`** in Visual Studio → F5 (console app). Tests: **Test → Run All Tests**.
Without Visual Studio: `g++ -std=c++17 SzyfrCezara/main.cpp SzyfrCezara/szyfr.cpp -o program.exe` (from this folder).
**Folders that year:** `desktopowa`, `konsolowa`, `testy` + file `egzamin` in the main folder. Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- function `szyfruj(tekst, klucz)` → encrypted string; only a–z (ASCII 97..122) shift, **space unchanged**
- key: any integer, negative or > 26; key 0 → same text
- text and key read from the keyboard in main
- part III: **unit tests** with the library available on the PC. One test method per case: abc,3→def · xyz,3→abc · def,-3→abc · abc,29→def · "ab cd",2→"cd ef"

## Key checks
- [ ] algorithm in a function returning a string, 2 params (string, int) read from the keyboard
- [ ] Caesar shift with wrap-around, spaces kept
- [ ] test methods with asserts and meaningful names
- [ ] the 5 cases, each in its own method, run (screenshot test1.png)
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
header above **szyfruj** (in `szyfr.cpp`): nazwa funkcji / opis funkcji / parametry / zwracany typ i opis / autor. Replace `00000000000` with **your exam number**.

## Notes
**Unit tests in Visual Studio (C++):**
1. Solution → Add → New Project → **Native Unit Test Project**.
2. Put the tested function in a `.h` + `.cpp` pair. In the test project: Add → Existing Item → the `.cpp`, and `#include "../Projekt/plik.h"`.
3. `TEST_METHOD(Nazwa) { Assert::AreEqual(string("def"), szyfruj("abc", 3)); }`
4. **Test → Run All Tests** → screenshot the Test Explorer.

This solution was built with MSBuild and its 5 tests passed in vstest.

## Related building blocks
`STR-14` – see the [catalog](../../README.md#building-blocks---full-catalog)
