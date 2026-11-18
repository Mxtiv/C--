// ======================================================================
// definitions: greedy conversion of litres into tanks / baths / gallons / litres
// Original file: Maths/litrysprawdzian/litry.cpp
// FIXED: this file now contains only the definition and #includes litry.h
// (the namespace + struct moved to the header)
// ======================================================================

#include "litry.h"

/********************************************************
 * nazwa funkcji: zamienLitry
 * opis funkcji: rozklada litry zachlannie: najpierw cysterny, potem wanny, galony, litry
 * parametry: ileLitrow - ilosc litrow, wynik - struktura do wypelnienia
 * zwracany typ i opis: brak (wynik przez referencje)
 * autor: <numer zdającego>
 ********************************************************/
void zamienLitry(int ileLitrow, Litry &wynik)
{
    wynik.cysterny = ileLitrow / pojemnosci::CYSTERNA;
    ileLitrow = ileLitrow % pojemnosci::CYSTERNA;

    wynik.wanny = ileLitrow / pojemnosci::WANNA;
    ileLitrow = ileLitrow % pojemnosci::WANNA;

    wynik.galony = ileLitrow / pojemnosci::GALON;
    ileLitrow = ileLitrow % pojemnosci::GALON;

    wynik.litry = ileLitrow;
}
