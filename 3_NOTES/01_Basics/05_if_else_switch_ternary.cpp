// ======================================================================
// ADDED (gap-fill): if / else if / else, nested if, switch (with fall-through), ternary
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int points = 73;

    // ---------------- if / else if / else ----------------
    if (points >= 90)
        cout << "grade 6" << endl;
    else if (points >= 75)
        cout << "grade 5" << endl;
    else if (points >= 50)
        cout << "grade 3" << endl;      // <- this one
    else
        cout << "grade 1" << endl;

    // Always use { } when there is more than one statement:
    if (points > 50)
    {
        cout << "passed" << endl;
        cout << "congratulations" << endl;
    }

    // ---------------- nested if + logical operators ----------------
    int year = 2024;
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        cout << year << " is a leap year" << endl;

    // ---------------- switch: only for int / char / enum (NOT string) ----------------
    int option = 2;
    switch (option)
    {
    case 1:
        cout << "Option one" << endl;
        break;                  // without break execution "falls through" to the next case
    case 2:
        cout << "Option two" << endl;
        break;
    case 3:
    case 4:                     // two cases sharing one block
        cout << "Option three or four" << endl;
        break;
    default:                    // when nothing matched
        cout << "Unknown option" << endl;
    }

    char answer = 'T';
    switch (answer)
    {
    case 't':
    case 'T':
        cout << "Yes" << endl;
        break;
    case 'n':
    case 'N':
        cout << "No" << endl;
        break;
    }

    // Declaring a variable inside a case needs its own { } block:
    switch (option)
    {
    case 2:
    {
        int local = option * 10;
        cout << "local = " << local << endl;
        break;
    }
    default:
        break;
    }

    // ---------------- ternary ----------------
    string parity = (points % 2 == 0) ? "even" : "odd";
    cout << points << " is " << parity << endl;

    // ---------------- comparing strings works with == for std::string ----------------
    string password = "abc";
    if (password == "abc") cout << "access granted" << endl;

    return 0;
}
