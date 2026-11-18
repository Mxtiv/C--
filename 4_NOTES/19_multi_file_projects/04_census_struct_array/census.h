// ======================================================================
// header: struct Obywatel + prototypes of the census functions
// Original file: unsorted/spisLudnosci/sprawdzian2.h
// FIXED - the bug was: the header did #include "census.cpp" and only forward-declared the
// struct. Now the struct is defined here and the .cpp includes this header.
// Build: g++ main.cpp census.cpp -o census.exe
// ======================================================================

#ifndef CENSUS_H
#define CENSUS_H

#include <string>
using namespace std;

struct Obywatel
{
    string imie;
    int wiek;
};

Obywatel *utworzTablice(int rozmiar);
void pobierzDane(Obywatel tablica[], int rozmiar);
void szukajPoImieniu(Obywatel tablica[], int rozmiar, string imie);
void szukajPoWieku(Obywatel tablica[], int rozmiar, int wiek);
void usunTablice(Obywatel tablica[]);

#endif
