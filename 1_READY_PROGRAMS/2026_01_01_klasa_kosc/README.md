# INF.04-01-26.01-SG – Klasa Kosc + testy jednostkowe (Visual Studio)

[⬅ all tasks](../README.md) · Sheet: [2026_01_01_SG](../../4_ARKUSZE/inf_04_2026_01_01_SG.pdf) · Key: [2026_01_01_SG_zo](../../4_ARKUSZE/klucze/INF_04_2026_01_01_SG_zo.pdf)

**Files:** Kosc.sln, Kosc/ (main.cpp, kosc.h, kosc.cpp), KoscTesty/ (testy.cpp) · **Run:** Open **`Kosc.sln`** in Visual Studio → F5 (console app). Tests: **Test → Run All Tests**.
Without Visual Studio: `g++ -std=c++17 Kosc/main.cpp Kosc/kosc.cpp -o program.exe` (from this folder).
**Folders that year:** `konsolowa`, `mobilna`, `dokumentacja` (+ unit tests). Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- public **static** instance counter; public fields: file names kosc0.png … kosc6.png (array), dots, file id, available (bool)
- constructor(value): not 1..6 → 0; dots = id = value; available; counter++
- constructor(): random 1..6; dots = id; available; counter++
- `rzuc()`: new random 1..6 **only when available**; `zablokuj()`: not available; method returning the value as text ("trzy")
- main: 2 objects (one per constructor, value from the keyboard); after each: count, dots as number and text, file name
- part III: **unit tests** of `rzuc()`: value in 1..6; value unchanged when blocked (separate methods)

## Key checks
- [ ] static counter, public fields, both constructors
- [ ] rzuc guarded by the availability flag
- [ ] text value
- [ ] two test methods with asserts and meaningful names, run
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
class header in `kosc.h` + method header above `rzuc` in `kosc.cpp`. Replace `00000000000` with **your exam number**.

## Notes
The unit-test steps are the same as in [2025_06_02_szyfr_cezara](../2025_06_02_szyfr_cezara/README.md). This solution was built with MSBuild and its 2 tests passed in vstest.

## Related building blocks
`CLS-02` · `RND-01` – see the [catalog](../../README.md#building-blocks---full-catalog)
