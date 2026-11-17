// ======================================================================
// definitions
// Original file: unsorted/dynArrayDemo/sprawdzian.cpp
// FIXED: struct moved to sprawdzian.h; this file now #includes the header
// ======================================================================

#include <iostream>
#include "sprawdzian.h"
using namespace std;

Osoby* utworzTablice(int rozmiar)                
{
    return new Osoby[rozmiar];
}
void wypelnianie(int rozmiar,  Osoby* tablica)
{
    for (int i = 0; i < rozmiar; i++)
    {
        cout << "Podaj kolejne imie: ";
        cin >> tablica[i].imie;
        cout << "\n";
        cout << "Podaj kolejne Nazwisko: ";
        cin >> tablica[i].Nazwisko;
        cout << "\n";
    }
}
void wypisanieOsob(int rozmiar, Osoby* tablica)
{
    for (int i= 0; i < rozmiar; i++)
    {
        cout << i+1 << "osoba: \n";
        cout << tablica[i].imie;
        cout << "\n" <<tablica[i].Nazwisko << "\n";
    }
}