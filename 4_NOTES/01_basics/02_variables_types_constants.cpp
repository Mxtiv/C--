// ======================================================================
// ADDED (gap-fill): variables, data types, constants, sizeof, scope
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

int licznikGlobalny = 0;        // global variable (visible everywhere below) - avoid when possible

int main()
{
    // ---------------- BASIC TYPES ----------------
    int calkowita = 42;             // integer            (4 bytes, about +-2.1 billion)
    long long duza = 9000000000;    // big integer        (8 bytes) - e.g. for factorial
    double rzeczywista = 3.14159;   // floating point     (8 bytes, ~15 digits) <- default choice
    float mniejsza = 2.5;           // smaller float      (4 bytes, ~7 digits) - rarely needed
    char litera = 'A';              // ONE character in SINGLE quotes
    bool flaga = true;              // true / false (prints 1 / 0)
    string tekst = "Ala ma kota";   // text in DOUBLE quotes (needs <string>)

    cout << calkowita << " " << duza << " " << rzeczywista << " " << mniejsza << endl;
    cout << litera << " " << flaga << " " << tekst << endl;

    // ---------------- ALWAYS GIVE A START VALUE ----------------
    int a = 5;      // good
    int b;          // UNINITIALIZED -> garbage value until you assign something
    b = 7;
    cout << a << " " << b << endl;

    // ---------------- CONSTANTS ----------------
    const double VAT = 0.23;        // cannot be changed later
    // VAT = 0.08;                  // ERROR: assignment of read-only variable
    const int ROZMIAR = 10;         // good for array sizes
    int tablica[ROZMIAR];
    tablica[0] = 0;
    cout << "VAT " << VAT << ", ROZMIAR " << ROZMIAR << ", tablica[0] " << tablica[0] << endl;

    // ---------------- sizeof = how many bytes a type takes ----------------
    cout << "sizeof(int)=" << sizeof(int) << " sizeof(double)=" << sizeof(double)
         << " sizeof(char)=" << sizeof(char) << " sizeof(bool)=" << sizeof(bool) << endl;

    // ---------------- OVERFLOW ----------------
    // int holds at most 2147483647. One more overflows (usually wraps to negative).
    // For big results (factorial, big sums) use long long.
    int maksInt = 2147483647;
    long long bezpieczna = (long long)maksInt + 1;
    cout << "2147483647 + 1 as long long = " << bezpieczna << endl;

    // ---------------- SCOPE ----------------
    licznikGlobalny++;
    {
        int wBloku = 1;             // exists only inside these { }
        cout << "inside block: " << wBloku << ", global: " << licznikGlobalny << endl;
    }
    // cout << wBloku;              // ERROR: not declared in this scope

    return 0;
}
