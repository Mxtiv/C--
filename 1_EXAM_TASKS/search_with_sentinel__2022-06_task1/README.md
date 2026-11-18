# INF.04-01-22.06-SG – Wyszukiwanie z wartownikiem

[⬅ all tasks](../README.md) · Sheet: [2022-06 task 1 SG](exam_sheet_2022-06_task1_SG.pdf) · Key: [2022-06 task 1 SG](grading_key_2022-06_task1_SG.xlsx)

**Files:** main.cpp · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsola`, `mobilna`, `dokumentacja`. Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- array of ≥ 50 random ints 1..100 (separate fill function)
- value to find from the keyboard; first occurrence
- search function puts the **sentinel at index n** and returns the index
- display the array **separated by commas** + the index, or a "not found" message
- main contains the test of the application

## Key checks
- [ ] main + fill function + search function
- [ ] search returns an index (number)
- [ ] sentinel inserted after the last element, loop from the first element until found
- [ ] message "not found" ONLY when the index is the sentinel's; the index ONLY otherwise
- [ ] random 1..100, value from keyboard, elements separated by commas
- [ ] no out-of-range access (array has n + 1 places)
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
header above **szukajZWartownikiem**: nazwa funkcji / argumenty / typ zwracany / informacje (algorithm name) / autor. Replace `00000000000` with **your exam number**.

## Related building blocks
`ARR-16` · `RND-02` – see the [catalog](../../README.md#building-blocks---full-catalog)
