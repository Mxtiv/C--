// ======================================================================
// multi-file: main.cpp + operacje.h + operacje.cpp
// Original file: unsorted/normalizacja/main.cpp
// Build: g++ main.cpp operacje.cpp -o program.exe
// ======================================================================

#include <iostream>
#include "operacje.h"
using namespace std;

int main()
{
    int litry;
    do
    {
        cout << "Podaj ilosc litrow: ";
        cin >> litry;
    } while (litry < 0);

    Normalizator wynik;
    policzLitry(litry, wynik);
    wypiszInformacje(wynik);

    return 0;
}
