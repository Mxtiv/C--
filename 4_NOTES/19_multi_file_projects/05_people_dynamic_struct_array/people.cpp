// ======================================================================
// definitions
// Original file: unsorted/dynArrayDemo/sprawdzian.cpp
// FIXED: struct moved to people.h; this file now #includes the header
// ======================================================================

#include <iostream>
#include "people.h"
using namespace std;

Osoba *utworzTablice(int rozmiar)
{
    return new Osoba[rozmiar];
}

void wypelnij(Osoba tablica[], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        cout << "Imie osoby nr " << i + 1 << ": ";
        cin >> tablica[i].imie;
        cout << "Nazwisko osoby nr " << i + 1 << ": ";
        cin >> tablica[i].nazwisko;
    }
}

void wypisz(Osoba tablica[], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        cout << i + 1 << ". " << tablica[i].imie << " " << tablica[i].nazwisko << endl;
    }
}
