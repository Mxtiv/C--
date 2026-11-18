// ======================================================================
// namespace constants, struct by reference, greedy conversion
// Original file: Maths/litrysprawdzian/main.cpp
// Build: g++ main.cpp litres.cpp -o litres.exe
// ======================================================================

#include <iostream>
#include "litres.h"
using namespace std;

int main()
{
    int ileLitrow;
    do
    {
        cout << "Podaj ilosc litrow: ";
        cin >> ileLitrow;
    } while (ileLitrow < 0);

    Litry wynik;
    zamienLitry(ileLitrow, wynik);

    cout << "Cysterny (" << pojemnosci::CYSTERNA << " l): " << wynik.cysterny << endl;
    cout << "Wanny (" << pojemnosci::WANNA << " l): " << wynik.wanny << endl;
    cout << "Galony (" << pojemnosci::GALON << " l): " << wynik.galony << endl;
    cout << "Litry: " << wynik.litry << endl;
    return 0;
}
