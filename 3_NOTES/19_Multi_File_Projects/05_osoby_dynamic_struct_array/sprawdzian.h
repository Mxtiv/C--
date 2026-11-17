// ======================================================================
// header: struct Osoby + prototypes
// Original file: unsorted/dynArrayDemo/sprawdzian.h
// FIXED - the bug was: the header did #include "sprawdzian.cpp". Now it only declares things.
// Build: g++ main.cpp sprawdzian.cpp -o osoby.exe
// ======================================================================

#ifndef SPRAWDZIAN_H
#define SPRAWDZIAN_H

#include <string>

struct Osoby
{
    std::string imie;
    std::string Nazwisko;
};

Osoby* utworzTablice(int rozmiar);
void wypelnianie(int rozmiar, Osoby* tablica);
void wypisanieOsob(int rozmiar, Osoby* tablica);

#endif
