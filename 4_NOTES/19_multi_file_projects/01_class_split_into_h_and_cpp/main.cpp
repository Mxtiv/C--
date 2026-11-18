// ======================================================================
// ADDED (gap-fill): main.cpp of a correctly split multi-file program
// Build (all .cpp files together!):   g++ main.cpp Prostokat.cpp -o program.exe
// VS Code "build active file" compiles ONE file only -> use the terminal for multi-file projects.
// ======================================================================

#include <iostream>
#include "Prostokat.h"     // dolaczamy NAGLOWEK, nigdy plik .cpp
using namespace std;

int main()
{
    Prostokat p1(3, 4);
    Prostokat p2(5, 5);
    Prostokat p3;          // konstruktor domyslny: 1 x 1

    p1.wypisz();
    cout << "pole " << p1.pole() << ", obwod " << p1.obwod() << endl;
    p2.wypisz();
    if (p2.czyKwadrat())
    {
        cout << "to jest kwadrat" << endl;
    }
    if (czyWiekszy(p2, p1))
    {
        cout << "p2 ma wieksze pole niz p1" << endl;
    }
    p3.wypisz();
    cout << "liczba prostokatow: " << Prostokat::ile() << endl;   // 3
    return 0;
}
