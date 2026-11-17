// ======================================================================
// ADDED (gap-fill): variables, data types, constants, sizeof, limits, auto
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
#include <string>
#include <climits>   // INT_MAX, INT_MIN
#include <cfloat>    // DBL_MAX
using namespace std;

int globalCounter = 0;          // global variable (visible everywhere below) - avoid when possible

int main()
{
    // ---------------- BASIC TYPES ----------------
    int whole = 42;                 // integer            (usually 4 bytes, about +-2.1 billion)
    long long big = 9000000000LL;   // big integer        (8 bytes)
    unsigned int positive = 7;      // no negative values
    short small = 100;              // 2 bytes
    double real = 3.14159;          // floating point     (8 bytes, ~15 digits) <- default choice
    float realF = 2.5f;             // smaller float      (4 bytes, ~7 digits) note the f
    char letter = 'A';              // ONE character in SINGLE quotes
    bool flag = true;               // true / false (prints 1 / 0)
    string text = "Ala ma kota";    // text in DOUBLE quotes (needs <string>)

    cout << whole << " " << big << " " << positive << " " << small << endl;
    cout << real << " " << realF << " " << letter << " " << flag << " " << text << endl;
    cout << boolalpha << flag << noboolalpha << endl;   // prints "true" instead of 1

    // ---------------- INITIALIZATION STYLES ----------------
    int a = 5;      // classic
    int b(5);       // constructor style
    int c{5};       // brace (uniform) init - refuses narrowing like int x{3.7};
    int d{};        // {} = zero-initialized -> 0
    int e;          // UNINITIALIZED -> garbage value! Always give a start value.
    (void)e;
    cout << a << b << c << d << endl;

    // ---------------- CONSTANTS ----------------
    const double VAT = 0.23;        // cannot be changed later
    // VAT = 0.08;                  // ERROR: assignment of read-only variable
    constexpr int SIZE = 10;        // compile-time constant - good for array sizes
    int table[SIZE] = {0};
    cout << "VAT " << VAT << ", SIZE " << SIZE << ", table[0] " << table[0] << endl;

    // ---------------- auto ----------------
    auto x = 10;        // int
    auto y = 2.5;       // double
    auto z = 'q';       // char
    auto s = string("hi");
    cout << x << " " << y << " " << z << " " << s << endl;

    // ---------------- sizeof + limits ----------------
    cout << "sizeof(int)=" << sizeof(int) << " sizeof(double)=" << sizeof(double)
         << " sizeof(char)=" << sizeof(char) << " sizeof(bool)=" << sizeof(bool) << endl;
    cout << "INT_MAX=" << INT_MAX << " INT_MIN=" << INT_MIN << " DBL_MAX=" << DBL_MAX << endl;

    // ---------------- OVERFLOW ----------------
    int max = INT_MAX;
    // max + 1 overflows -> undefined behaviour (usually wraps to negative). Use long long for big results
    long long safe = (long long)max + 1;
    cout << "INT_MAX + 1 as long long = " << safe << endl;

    // ---------------- SCOPE ----------------
    globalCounter++;
    {
        int insideBlock = 1;        // exists only inside these { }
        cout << "inside block: " << insideBlock << ", global: " << globalCounter << endl;
    }
    // cout << insideBlock;         // ERROR: not declared in this scope

    return 0;
}
