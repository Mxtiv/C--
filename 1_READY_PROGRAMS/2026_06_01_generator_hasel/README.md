# INF.04-01-26.06-SG – Generator bezpiecznych haseł (12 znaków)

[⬅ all tasks](../README.md) · Sheet: [2026_06_01_SG](../../4_ARKUSZE/inf_04_2026_06_01_SG.pdf) · Key: [2026_06_01_SG_zo](../../4_ARKUSZE/klucze/INF_04_2026_06_01_SG_zo.pdf)

**Files:** main.cpp, znaki.txt · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsolowa`, `webowa`, `dokumentacja` (archive `Web1.7z` → `znaki.txt`). Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- no built-in password generators; the password is kept in a string variable
- a function returns a **12-character** password: 3 lower-case, 3 upper-case, **2 Polish letters** (ąęłńóśżźĄĘŁŃÓŚŻŹ, file znaki.txt), 2 digits, 2 specials `!@#$%^&*()_+`
- each character is placed at a **random position** of the password
- main generates **5** passwords and shows them with a message

## Key checks
- [ ] function returning a string, 12 characters
- [ ] the right number from each set
- [ ] random positions
- [ ] 5 passwords displayed
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
header of any function (here `generujHaslo`; the 2026 pattern has no stars): nazwa funkcji / opis funkcji / parametry / zwracany typ i opis / autor. Replace `00000000000` with **your exam number**.

## Notes
Polish letters → **wide strings** (`wstring`, `wcout` in UTF-16 mode). The file is saved as UTF-8 **with BOM**.

## Related building blocks
`RND-06` · `RND-07` – see the [catalog](../../README.md#building-blocks---full-catalog)
