// ======================================================================
// macro with the comma operator
// Original file: unsorted/various/macrofunctions2.cpp
// FIXED - the bug was: counts the terminating 0 as an entry
// ======================================================================

#include <iostream>
#define OBLICZ_SREDNIA(liczba) (suma += liczba, licznik++) 
using namespace std;
int main()
{
    int suma = 0;
    int licznik = 0;
    int liczba;
    cout << "Podaj liczby (wprowadź 0, aby zakończyć):" << endl;
    do
    {
        cout << "Liczba " << licznik + 1 << ": ";
        cin >> liczba;
        if (liczba != 0)            // 0 only ends the input, it is not a value

            OBLICZ_SREDNIA(liczba);
    } while (liczba != 0);

    if (licznik > 0)
    {
        double srednia = static_cast<double>(suma) / licznik;
        cout << "Średnia wprowadzonych liczb: " << srednia << endl;
    }
    else
    {
        cout << "Nie wprowadzono żadnych liczb." << endl;
    }

    return 0;
}