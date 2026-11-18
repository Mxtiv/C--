// ======================================================================
// #if / #elif / #else / #endif
// Original file: Preprocessing/conditions.cpp
// Kompilowany jest TYLKO jeden fragment - reszty kompilator w ogole nie widzi.
// ======================================================================

#include <iostream>
using namespace std;

#define WERSJA 2

int main()
{
#if WERSJA == 1
    cout << "Wersja 1" << endl;
#elif WERSJA == 2
    cout << "Wersja 2" << endl;
#else
    cout << "Nieznana wersja" << endl;
#endif
    return 0;
}
