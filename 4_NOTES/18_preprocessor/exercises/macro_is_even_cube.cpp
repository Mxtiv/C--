// ======================================================================
// CZY_PARZYSTA(n), SZESCIAN(x)
// Original file: unsorted/various/macros.cpp
// FIXED - the bug was: global h = n is 0, so CUBE(h) is always 0; local n shadows the global
// ======================================================================

#include <iostream>
using namespace std;

#define CZY_PARZYSTA(n) ((n) % 2 == 0)
#define SZESCIAN(x) ((x) * (x) * (x))

int main()
{
    int n;
    cout << "Podaj liczbe: ";
    cin >> n;

    if (CZY_PARZYSTA(n))
    {
        cout << n << " jest parzysta" << endl;
    }
    else
    {
        cout << n << " jest nieparzysta" << endl;
    }

    int szescian = SZESCIAN(n);
    cout << "Szescian: " << szescian << endl;
    if (CZY_PARZYSTA(szescian))
    {
        cout << "Szescian jest parzysty" << endl;
    }
    else
    {
        cout << "Szescian jest nieparzysty" << endl;
    }

    return 0;
}
