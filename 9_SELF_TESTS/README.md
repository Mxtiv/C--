# 9_SELF_TESTS – checks of the toolbox itself (not needed at the exam)

[⬅ main index](../README.md)

Double-click **`sprawdz_wszystko.bat`**, or run it from a terminal. It:
1. compiles every official task, every practice program, every building-block file and the start template with **g++** (MSYS2 `C:\msys64\ucrt64\bin` or g++ on PATH);
2. compiles every official task with **MSVC** using default settings, i.e. the way a fresh Visual Studio project would;
3. runs every official task with scripted keyboard input and checks the output against the sheet and key. Examples: the sieve prints exactly the 25 primes; dice ask again for 2 and 11; the lottery has no repeats; passwords are 3 + 3 + 2 + 2 + 2 characters; 1506404300 is printed correctly;
4. builds the two Visual Studio solutions with **MSBuild** and runs their **unit tests** with vstest (5 + 2 tests).

It ends with `N passed, 0 failed`. Visual Studio steps are skipped when VS (C++ workload) is not installed.
