# 00_Start_Here - Start here - compiling, running, reading errors

[⬅ notes index](../README.md) · [main index](../../README.md)

> **Paste-ready code for this topic:** [2_BUILDING_BLOCKS/00_START_TEMPLATE.cpp](../../2_BUILDING_BLOCKS/00_START_TEMPLATE.cpp)

How to turn a `.cpp` file into a program and what the most common compiler errors mean.

### Compile & run (terminal, MSYS2 g++ that is already on this PC)
```bash
g++ file.cpp -o program.exe          # compile one file
.\program.exe                        # run it (PowerShell)
g++ -std=c++17 -Wall file.cpp -o program.exe   # recommended: modern C++ + warnings
g++ main.cpp other.cpp -o program.exe          # multi-file project: list ALL .cpp files
```
In VS Code: open a `.cpp` file and press **Ctrl+Shift+B** (task *"g++.exe build active file"* from `.vscode/tasks.json`). It builds only the open file, so use the terminal for multi-file projects.

### Error messages decoded
| Message (fragment) | Usually means |
|---|---|
| `'cout' was not declared in this scope` | missing `#include <iostream>` or `using namespace std;` |
| `expected ';' before ...` | missing semicolon on the line ABOVE |
| `expected '}' at end of input` | a `{` was never closed |
| `a function-definition is not allowed here` | you wrote a function inside `main()` - move it above `main` |
| `redefinition of 'struct X'` | the struct is defined twice (e.g. in .h AND .cpp) |
| `undefined reference to 'foo'` | declared but never defined, or you forgot a `.cpp` on the g++ line |
| `undefined reference to 'WinMain'` / `main` | the file has no `main()` |
| `'x' is private within this context` | accessing a private member from outside - use a getter/setter |
| `no matching function for call to` | wrong number/types of arguments |
| `invalid conversion from 'const char*' to 'char'` | `"x"` (string) used where `'x'` (char) is needed |
| warning `suggest parentheses around assignment` | you wrote `if (a = b)` - you meant `==` |
| warning `... is used uninitialized` | variable has no start value - give it one |
