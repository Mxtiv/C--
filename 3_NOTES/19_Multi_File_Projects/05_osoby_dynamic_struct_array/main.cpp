// ======================================================================
// dynamic array of structs created by a function from another file
// Original file: unsorted/dynArrayDemo/main.cpp
// FIXED - the bugs were: new Osoby[liczbaOsob] ran BEFORE liczbaOsob was read (garbage size),
// two arrays were allocated (one unused) and nothing was freed with delete[].
// Build: g++ main.cpp sprawdzian.cpp -o osoby.exe
// ======================================================================

#include <iostream>
#include "sprawdzian.h"
using namespace std;

int main()
{
    int liczbaOsob;
    cout << "Podaj ile osob chcesz wprowadzic: ";
    cin >> liczbaOsob;                               // read the size FIRST...

    Osoby *tablica = utworzTablice(liczbaOsob);      // ...then allocate
    cout << "\n";
    wypelnianie(liczbaOsob, tablica);
    wypisanieOsob(liczbaOsob, tablica);

    delete[] tablica;                                // free what new[] allocated
    return 0;
}
