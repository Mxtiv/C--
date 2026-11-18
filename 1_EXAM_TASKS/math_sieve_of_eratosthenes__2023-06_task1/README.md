# INF.04-01-23.06-SG – Sito Eratostenesa (n = 100)

[⬅ all tasks](../README.md) · Sheet: [2023-06 task 1 SG](exam_sheet_2023-06_task1_SG.pdf) · Key: [2023-06 task 1 SG](grading_key_2023-06_task1_SG.xlsx)

**Files:** main.cpp · **Run:** `g++ -std=c++17 main.cpp -o program.exe` (in this folder), or create a C++ console project in Visual Studio and paste `main.cpp`.
**Folders that year:** `konsola`, `desktop`, `dokumentacja`. Zip the whole console project, and put the source + exe outside the zip.

## Task (from the sheet)
- bool array A[2..n], n = 100, initially true; pseudocode: for i = 2 while i ≤ √n: if A[i]: for j = 2i, 3i … ≤ n: A[j] = false
- filling in a **separate function** taking the array, returning nothing (void)
- print the primes with a separator, after a meaningful message

## Key checks
- [ ] function with an array argument, void
- [ ] outer loop 2..10 (√100), inner loop sets false for multiples
- [ ] output: 2 3 5 7 11 … 97 (only primes)
- [ ] meaningful names (A allowed - as in the pseudocode)
- [ ] readable code, meaningful names, runs (screenshot of the whole screen with the IDE + taskbar)

## Documentation comment
header above **wypelnijSito**: nazwa funkcji / parametry wejściowe / wartość zwracana / informacje / autor. Replace `00000000000` with **your exam number**.

## Related building blocks
`NUM-02` – see the [catalog](../../README.md#building-blocks---full-catalog)
