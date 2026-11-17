// ======================================================================
// ADDED (gap-fill): reading input (cin, getline) and formatting output (iomanip)
// Not from your original repo - written to fill a missing topic.
// This program ASKS for input when you run it.
// ======================================================================

#include <iostream>
#include <iomanip>   // setw, setprecision, fixed, setfill, left, right
#include <string>
#include <limits>    // numeric_limits (for clearing bad input)
using namespace std;

int main()
{
    // ---------------- cin >> reads ONE word / number (stops at space) ----------------
    int age;
    cout << "Age: ";
    cin >> age;

    // ---------------- input validation (user typed letters instead of a number) ----------------
    while (cin.fail() || age < 0)
    {
        cin.clear();                                            // reset the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');    // throw away the bad line
        cout << "Wrong value, try again: ";
        cin >> age;
    }

    // ---------------- getline reads a WHOLE line (with spaces) ----------------
    // After cin >> there is a leftover '\n' in the buffer -> getline would read an empty line.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');        // so: ignore it first!
    string fullName;
    cout << "Full name (with space): ";
    getline(cin, fullName);

    // ---------------- several values in one line ----------------
    double a, b;
    cout << "Two numbers separated by space: ";
    cin >> a >> b;

    // ---------------- OUTPUT FORMATTING ----------------
    cout << "\nHello " << fullName << ", age " << age << endl;

    cout << fixed << setprecision(2);                   // always 2 digits after the dot
    cout << "a / b = " << a / b << endl;                // e.g. 3.33
    cout << "pi    = " << 3.14159265 << endl;           // 3.14
    cout.unsetf(ios::fixed);                            // back to default formatting
    cout << setprecision(6);

    // table with columns: setw(n) sets the width of the NEXT item only
    cout << left  << setw(10) << "Name" << right << setw(8) << "Score" << endl;
    cout << left  << setw(10) << "Ala"  << right << setw(8) << 95 << endl;
    cout << left  << setw(10) << "Bartek" << right << setw(8) << 7 << endl;

    // leading zeros, e.g. dates 05.03.2024
    cout << setfill('0') << setw(2) << 5 << "." << setw(2) << 3 << ".2024" << setfill(' ') << endl;

    // other number formats
    cout << "255 in hex: " << hex << 255 << ", in oct: " << oct << 255 << dec << endl;

    // ---------------- cerr = error stream ----------------
    if (b == 0) cerr << "Warning: division by zero above!" << endl;

    return 0;
}
