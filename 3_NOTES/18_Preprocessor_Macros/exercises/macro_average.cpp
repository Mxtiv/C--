// ======================================================================
// macro SREDNIA(a, b)
// Original file: unsorted/various/macroAvg.cpp
// ======================================================================

#include <iostream>
using namespace std;

#define SREDNIA(a, b) (((a) + (b)) / 2.0)     // 2.0, zeby dzielenie nie bylo calkowite

int main()
{
    int liczba1, liczba2;
    cout << "Podaj dwie liczby: ";
    cin >> liczba1 >> liczba2;

    double srednia = SREDNIA(liczba1, liczba2);
    cout << "Srednia: " << srednia << endl;

    return 0;
}
