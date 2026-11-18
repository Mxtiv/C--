// ======================================================================
// header: struct Osoba + prototypes
// Original file: unsorted/dynArrayDemo/sprawdzian.h
// FIXED - the bug was: the header did #include "people.cpp". Now it only declares things.
// Build: g++ main.cpp people.cpp -o people.exe
// ======================================================================

#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>
using namespace std;

struct Osoba
{
    string imie;
    string nazwisko;
};

Osoba *utworzTablice(int rozmiar);
void wypelnij(Osoba tablica[], int rozmiar);
void wypisz(Osoba tablica[], int rozmiar);

#endif
