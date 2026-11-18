// ======================================================================
// dynamic array of structs created by a function from another file
// Original file: unsorted/dynArrayDemo/main.cpp
// FIXED - the bugs were: new Osoby[liczbaOsob] ran BEFORE liczbaOsob was read (garbage size),
// two arrays were allocated (one unused) and nothing was freed with delete[].
// Build: g++ main.cpp people.cpp -o people.exe
// ======================================================================

#include <iostream>
#include "people.h"
using namespace std;

int main()
{
    int liczbaOsob;
    do
    {
        cout << "Ile osob wprowadzic (1-50): ";
        cin >> liczbaOsob;                       // NAJPIERW wczytaj rozmiar...
    } while (liczbaOsob < 1 || liczbaOsob > 50);

    Osoba *tablica = utworzTablice(liczbaOsob);  // ...POTEM utworz tablice
    wypelnij(tablica, liczbaOsob);
    wypisz(tablica, liczbaOsob);

    delete[] tablica;                            // zwolnij to, co przydzielil new[]
    return 0;
}
