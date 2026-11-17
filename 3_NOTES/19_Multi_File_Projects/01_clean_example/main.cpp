// ======================================================================
// ADDED (gap-fill): main.cpp of a correctly split multi-file program
// Build (all .cpp files together!):   g++ main.cpp Prostokat.cpp -o program.exe
// VS Code "build active file" compiles ONE file only -> use the terminal for multi-file projects.
// ======================================================================

#include <iostream>
#include "Prostokat.h"     // include the HEADER, never the .cpp
using namespace std;

int main()
{
    Prostokat p1(3, 4);
    Prostokat p2(5, 5);
    Prostokat p3;          // defaults 1 x 1

    cout << p1.opis() << ": pole " << p1.pole() << ", obwod " << p1.obwod() << endl;
    cout << p2.opis() << ": pole " << p2.pole() << endl;
    cout << "kwadrat? " << boolalpha << czyKwadrat(p2, 5, 5) << endl;
    cout << "liczba prostokatow: " << Prostokat::ile() << endl;   // 3
    (void)p3;
    return 0;
}
