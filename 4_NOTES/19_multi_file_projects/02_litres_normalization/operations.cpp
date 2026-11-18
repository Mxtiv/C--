// ======================================================================
// function definitions
// Original file: unsorted/normalizacja/operacje.cpp
// FIXED: removed the duplicate struct definition (it already comes from operations.h)
// ======================================================================

#include <iostream>
#include "operations.h"
using namespace std;

// (struct Normalizator NIE jest tu definiowana drugi raz - pochodzi z operations.h.
//  Dwie definicje w jednym pliku = blad "redefinition of struct".)

/********************************************************
 * nazwa funkcji: policzLitry
 * opis funkcji: rozklada litry na cysterny (1000 l), wanny (200 l), galony (5 l) i litry
 * parametry: wszystkieLitry - ilosc litrow, wynik - struktura do wypelnienia
 * zwracany typ i opis: brak (wynik przez referencje)
 * autor: <numer zdającego>
 ********************************************************/
void policzLitry(int wszystkieLitry, Normalizator &wynik)
{
    wynik.cysterny = wszystkieLitry / 1000;
    wszystkieLitry = wszystkieLitry % 1000;
    wynik.wanny = wszystkieLitry / 200;
    wszystkieLitry = wszystkieLitry % 200;
    wynik.galony = wszystkieLitry / 5;
    wszystkieLitry = wszystkieLitry % 5;
    wynik.litry = wszystkieLitry;
}

/********************************************************
 * nazwa funkcji: wypiszInformacje
 * opis funkcji: wypisuje wynik rozkladu
 * parametry: wynik - struktura z rozkladem
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void wypiszInformacje(Normalizator wynik)
{
    cout << "Cysterny: " << wynik.cysterny << endl;
    cout << "Wanny: " << wynik.wanny << endl;
    cout << "Galony: " << wynik.galony << endl;
    cout << "Litry: " << wynik.litry << endl;
}
