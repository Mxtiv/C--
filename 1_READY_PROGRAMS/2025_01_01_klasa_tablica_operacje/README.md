# INF.04-01-25.01-SG – Klasa z tablicą – operacje (wyszukiwanie, nieparzyste, średnia)

[⬅ all tasks](../README.md) · Sheet: [2025_01_01_SG](../../4_ARKUSZE/inf_04_2025_01_01_SG.pdf) · Key: [2025_01_01_SG_zo](../../4_ARKUSZE/klucze/inf_04_2025_01_01_SG_zo.pdf)

**Files:** main.cpp · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsolowa`, `webowa`, `dokumentacja`. Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- fields **private**: a traditional int array + the actual element count
- constructor(size): sets the count, fills with random **1..1000**
- public methods: display "<i>: <value>"; find first → index or **-1**; display odd values and return how many; average
- main: object with size > 20; message with the index only when found; odd count with a comment; average

## Key checks
- [ ] array + count fields private
- [ ] constructor takes the size, random 1..1000
- [ ] four public methods with the right return types
- [ ] main tests all of them; nothing printed when not found
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
header of any method: nazwa metody / opis metody / parametry (or "brak") / zwracany typ i opis / autor. Replace `00000000000` with **your exam number**.

## Related building blocks
`CLS-03` · `ARR-01` · `ARR-13` · `ARR-12` · `ARR-04` – see the [catalog](../../README.md#building-blocks---full-catalog)
