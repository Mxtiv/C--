// ======================================================================
// ADDED (gap-fill): reading input (cin, getline) and formatting output (iomanip)
// Not from your original repo - written to fill a missing topic.
// This program ASKS for input when you run it.
// ======================================================================

#include <iostream>
#include <string>
#include <iomanip>   // setprecision, fixed, setw  <- the topic of this file (exam code: plain cout)
using namespace std;

int main()
{
    // ---------------- cin >> reads ONE word / number (stops at space) ----------------
    int wiek;
    do
    {
        cout << "Age (0-120): ";
        cin >> wiek;
    } while (wiek < 0 || wiek > 120);      // simple validation: ask again until it is OK

    // ---------------- getline reads a WHOLE line (with spaces) ----------------
    // After cin >> there is a leftover '\n' in the buffer -> getline would read an empty line.
    cin.ignore();                           // so: ignore it first!
    string imieNazwisko;
    cout << "Full name (with space): ";
    getline(cin, imieNazwisko);

    // ---------------- several values in one line ----------------
    double a, b;
    cout << "Two numbers separated by space: ";
    cin >> a >> b;

    cout << "Hello " << imieNazwisko << ", age " << wiek << endl;
    if (b != 0)
    {
        cout << "a / b = " << a / b << endl;          // plain cout: e.g. 3.33333
    }

    // ---------------- iomanip (the topic) ----------------
    cout << fixed << setprecision(2);                 // from now on: 2 digits after the dot
    cout << "pi = " << 3.14159265 << endl;            // 3.14

    // setw(n) sets the width of the NEXT item only (for simple tables)
    cout << setw(10) << "Name" << setw(8) << "Score" << endl;
    cout << setw(10) << "Ala" << setw(8) << 95 << endl;

    return 0;
}
