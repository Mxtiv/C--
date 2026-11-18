// ======================================================================
// ADDED (gap-fill): if / else if / else, switch (with fall-through), ternary
// Not from your original repo - written to fill a missing topic.
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int punkty = 73;

    // ---------------- if / else if / else ----------------
    if (punkty >= 90)
    {
        cout << "grade 6" << endl;
    }
    else if (punkty >= 75)
    {
        cout << "grade 5" << endl;
    }
    else if (punkty >= 50)
    {
        cout << "grade 3" << endl;      // <- this one
    }
    else
    {
        cout << "grade 1" << endl;
    }

    // ---------------- condition with logical operators ----------------
    int rok = 2024;
    if ((rok % 4 == 0 && rok % 100 != 0) || rok % 400 == 0)
    {
        cout << rok << " is a leap year" << endl;
    }

    // ---------------- switch: only for int / char (NOT string) ----------------
    int opcja = 2;
    switch (opcja)
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
        break;
    }

    char odpowiedz = 'T';
    switch (odpowiedz)
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

    // ---------------- ternary  condition ? ifTrue : ifFalse ----------------
    // Short form of if/else that gives a value. You will SEE it in other code;
    // in your own exam code just write the if/else below - it does the same.
    string parzystosc = (punkty % 2 == 0) ? "even" : "odd";
    cout << punkty << " is " << parzystosc << endl;

    if (punkty % 2 == 0)
    {
        parzystosc = "even";
    }
    else
    {
        parzystosc = "odd";
    }
    cout << punkty << " is " << parzystosc << endl;

    // ---------------- comparing strings works with == for std::string ----------------
    string haslo = "abc";
    if (haslo == "abc")
    {
        cout << "access granted" << endl;
    }

    return 0;
}
