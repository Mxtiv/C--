// ======================================================================
// header: struct obywatel + prototypes of the census functions
// Original file: unsorted/spisLudnosci/sprawdzian2.h
// FIXED - the bug was: the header did #include "sprawdzian2.cpp" and only forward-declared the
// struct. Now the struct is defined here and the .cpp includes this header.
// Build: g++ main.cpp sprawdzian2.cpp -o spis.exe
// ======================================================================

#ifndef SPRAWDZIAN2_H
#define SPRAWDZIAN2_H

#include <string>

struct obywatel                      // deklaracja struktury o nazwie obywatel
{
    int wiek;
    std::string imie;
};

obywatel* utworzTablice(int rozmiar);
void pobierzDane(obywatel tablica[], int rozmiar);
void wyszukajPoString(obywatel tablica[], int rozmiar, std::string wartosc);
void wyszukajPoInt(obywatel tablica[], int rozmiar, int wartosc);
void usunDane(obywatel tablica[], int rozmiar);

#endif
