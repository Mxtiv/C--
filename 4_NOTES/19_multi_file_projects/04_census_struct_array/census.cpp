// ======================================================================
// definitions
// Original file: unsorted/spisLudnosci/sprawdzian2.cpp
// FIXED: struct moved to census.h; this file now #includes the header (not the other way round)
// ======================================================================

#include <iostream>
#include "census.h"   // struct Obywatel + prototypy
using namespace std;

/********************************************************
 * nazwa funkcji: utworzTablice
 * opis funkcji: tworzy dynamiczna tablice obywateli
 * parametry: rozmiar - liczba obywateli
 * zwracany typ i opis: Obywatel* - wskaznik na nowa tablice
 * autor: <numer zdającego>
 ********************************************************/
Obywatel *utworzTablice(int rozmiar)
{
    return new Obywatel[rozmiar];
}

/********************************************************
 * nazwa funkcji: pobierzDane
 * opis funkcji: wczytuje imie i wiek kazdego obywatela
 * parametry: tablica - tablica obywateli, rozmiar - liczba obywateli
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void pobierzDane(Obywatel tablica[], int rozmiar)
{
    for (int i = 0; i < rozmiar; i++)
    {
        cout << "Obywatel nr " << i + 1 << endl;
        cout << "Imie: ";
        cin >> tablica[i].imie;
        cout << "Wiek: ";
        cin >> tablica[i].wiek;
    }
}

/********************************************************
 * nazwa funkcji: szukajPoImieniu
 * opis funkcji: wypisuje wszystkich obywateli o podanym imieniu
 * parametry: tablica, rozmiar - dane, imie - szukane imie
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void szukajPoImieniu(Obywatel tablica[], int rozmiar, string imie)
{
    bool znaleziono = false;
    for (int i = 0; i < rozmiar; i++)
    {
        if (tablica[i].imie == imie)
        {
            znaleziono = true;
            cout << "Znaleziono: " << tablica[i].imie << ", " << tablica[i].wiek << " lat" << endl;
        }
    }
    if (!znaleziono)
    {
        cout << "Nie znaleziono obywatela o tym imieniu." << endl;
    }
}

/********************************************************
 * nazwa funkcji: szukajPoWieku
 * opis funkcji: wypisuje wszystkich obywateli w podanym wieku
 * parametry: tablica, rozmiar - dane, wiek - szukany wiek
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void szukajPoWieku(Obywatel tablica[], int rozmiar, int wiek)
{
    bool znaleziono = false;
    for (int i = 0; i < rozmiar; i++)
    {
        if (tablica[i].wiek == wiek)
        {
            znaleziono = true;
            cout << "Znaleziono: " << tablica[i].imie << ", " << tablica[i].wiek << " lat" << endl;
        }
    }
    if (!znaleziono)
    {
        cout << "Nie znaleziono obywatela w tym wieku." << endl;
    }
}

/********************************************************
 * nazwa funkcji: usunTablice
 * opis funkcji: zwalnia pamiec tablicy utworzonej przez new[]
 * parametry: tablica - tablica do usuniecia
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void usunTablice(Obywatel tablica[])
{
    delete[] tablica;
}
