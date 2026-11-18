// ======================================================================
// macro that changes two variables (suma and licznik) - running average, 0 ends the input
// Original file: unsorted/various/macrofunctions2.cpp
// FIXED - the bug was: counts the terminating 0 as an entry
// ======================================================================

#include <iostream>
using namespace std;

// makro wstawia DWIE instrukcje - uzywaj go zawsze w { }
#define DODAJ(x) suma = suma + (x); licznik++

int main()
{
    int suma = 0;
    int licznik = 0;
    int liczba;

    cout << "Podaj liczby (0 konczy):" << endl;
    do
    {
        cout << "Liczba " << licznik + 1 << ": ";
        cin >> liczba;
        if (liczba != 0)            // 0 tylko konczy wpisywanie, nie jest wartoscia
        {
            DODAJ(liczba);
        }
    } while (liczba != 0);

    if (licznik > 0)
    {
        double srednia = (double)suma / licznik;
        cout << "Srednia: " << srednia << endl;
    }
    else
    {
        cout << "Nie podano zadnych liczb." << endl;
    }

    return 0;
}
