# How the code in this toolbox is written

[⬅ main index](README.md)

Every program, block and note uses the same **plain exam style**: only things you would normally write at INF.04 and can retype from memory. If something here looks unfamiliar, it shouldn't be in the toolbox.

## 1. Headers

Always `using namespace std;`.

| Header | For |
|---|---|
| `<iostream>` | `cout`, `cin` |
| `<string>` | `string`, `getline`, `stoi`, `to_string` |
| `<cstdlib>` + `<ctime>` | `rand`, `srand(time(0))` |
| `<fstream>` | files |
| `<cmath>` | `sqrt`, `pow`, `round` |
| `<cctype>` | `isdigit`, `isalpha`, `toupper`, `tolower` |
| `<clocale>` | only `setlocale(LC_ALL, "");` for Polish letters in the console |

Used **only in their own topic** (the vector / exceptions / templates blocks and the matching 4_NOTES chapters): `<vector>`, `<stdexcept>`, `<exception>`. Not used at all: `<algorithm> <numeric> <functional> <utility> <limits> <iomanip> <sstream> <random> <map> <set> <memory>`.

## 2. Loops

```cpp
for (int i = 0; i < n; i++)      // yes
for (int x : tab)                // no - range-for
for (auto x : tab)               // no - auto
for (int i = 0; i < tekst.length(); i++)   // yes - over a string (the compiler may warn about signed/unsigned, that's fine)
```

## 3. Arrays instead of vector

A plain array + the number of elements. Functions get `int tab[], int n`.

```cpp
const int ROZMIAR = 100;
int liczby[ROZMIAR];
int ile = 0;                     // how many are really used
```

When a function finds many results ("all indexes"), it writes them to a second array and returns how many there are (or just prints them).

## 4. Parameters

By value, strings too. `&` only when a function has to give back more than one value.

```cpp
int policzSamogloski(string tekst)                        // yes
int policzSamogloski(const string &tekst)                 // no
void minMax(int tab[], int n, int &min, int &max)         // yes - two results
```

No `const` on parameters or methods.

## 5. Write it yourself

| Instead of | Write |
|---|---|
| `a > b ? a : b` | `if` / `else` |
| `swap(a, b)` | `int pomocnicza = a; a = b; b = pomocnicza;` |
| `sort`, `reverse`, `find`, `count`, `min_element`, `accumulate` | your own loop |
| `stringstream` | walk the string character by character |
| `setw`, `setprecision` | plain `cout` |
| lambdas | a normal function |

## 6. Input

```cpp
do
{
    cout << "Podaj liczbe od 3 do 10: ";
    cin >> liczba;
} while (liczba < 3 || liczba > 10);
```

A whole line: `getline(cin, tekst);`. If there was a `cin >>` before it, put `cin.ignore();` first.
No `cin.clear()`, `numeric_limits`, `cin >> ws`.

## 7. Random numbers

```cpp
srand(time(0));                          // once, at the start of main
int liczba = rand() % (max - min + 1) + min;
```

## 8. Types

`int`, `double`, `bool`, `char`, `string`; `long long` only for really big results (factorial).
No `size_t`, `unsigned`, `static_cast` (write `(int)x` or `(double)x`), `nullptr` (except the pointers chapter). `time(0)`, not `time(nullptr)`.

## 9. Classes

```cpp
class Film
{
private:
    string tytul;
    int liczbaWypozyczen;

public:
    Film()
    {
        tytul = "";
        liczbaWypozyczen = 0;
    }

    void setTytul(string nowyTytul)
    {
        tytul = nowyTytul;
    }

    string getTytul()
    {
        return tytul;
    }
};
```

- fields `private` (or `protected` when derived classes need them);
- the constructor assigns in its body, no `: pole(wartosc)` list;
- parameter names differ from field names, so `this->` isn't needed;
- `virtual` and `= 0` only when the task asks for them; no `override`, no virtual destructors;
- `friend` and operators only in their own topic file.

## 10. Formatting

Braces on their own lines and always written (even for one line), 4 spaces, Polish names, the INF.04 comment box above each function / class.

## 11. Polish letters

Plain `string` + `setlocale(LC_ALL, "");`. No `wstring` / `wcout`.
