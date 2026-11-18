# INF.04-01-24.01-SG – PESEL – płeć i suma kontrolna

[⬅ all tasks](../README.md) · Sheet: [2024_01_01_SG](../../4_ARKUSZE/inf_04_2024_01_01_SG.pdf) · Key: [2024_01_01_SG_zo](../../4_ARKUSZE/klucze/INF_04_2024_01_01_SG_zo.pdf)

**Files:** main.cpp · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsola`, `desktopowa`, `dokumentacja`. Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- PESEL kept as a string (or array of 11), initialised with your PESEL or **55030101193**
- function → `char` **'K'** (10th digit even) / **'M'** (odd)
- function → `bool` checksum: weights 1 3 7 9 1 3 7 9 1 3, S = Σ, M = S % 10, R = M == 0 ? 0 : 10 - M, R == 11th digit
- main: read PESEL, print "Kobieta"/"Mężczyzna" and checksum OK / not OK

## Key checks
- [ ] functions take the PESEL variable; `return` on every path
- [ ] sex function char K/M from the 10th digit
- [ ] products of digits and weights summed
- [ ] M = S % 10; R = 10 - M or 0
- [ ] compare R with the 11th digit
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
header above any function: nazwa funkcji / opis funkcji / parametry / zwracany typ i opis / autor. Replace `00000000000` with **your exam number**.

## Related building blocks
`PESEL-03` · `PESEL-04` · `PESEL-02` – see the [catalog](../../README.md#building-blocks---full-catalog)
