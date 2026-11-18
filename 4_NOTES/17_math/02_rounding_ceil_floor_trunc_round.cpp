// ======================================================================
// rounding table incl. negative numbers
// Original file: unsorted/various/microfunctions3.cpp
//
//   ceil  - zawsze w gore        ( 4.3 ->  5,  -4.3 -> -4)
//   floor - zawsze w dol         ( 4.3 ->  4,  -4.3 -> -5)
//   trunc - obcina ulamek        ( 4.7 ->  4,  -4.7 -> -4)
//   round - do najblizszej, .5 od zera ( 4.5 -> 5, -4.5 -> -5)
// ======================================================================

#include <iostream>
#include <cmath>
using namespace std;

/********************************************************
 * nazwa funkcji: pokazZaokraglenia
 * opis funkcji: wypisuje wynik ceil, floor, trunc i round dla liczby
 * parametry: wartosc - liczba do zaokraglenia
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void pokazZaokraglenia(double wartosc)
{
    cout << "Wartosc: " << wartosc << endl;
    cout << "  ceil:  " << ceil(wartosc) << endl;
    cout << "  floor: " << floor(wartosc) << endl;
    cout << "  trunc: " << trunc(wartosc) << endl;
    cout << "  round: " << round(wartosc) << endl;
}

int main()
{
    double wartosci[6] = {4.3, 4.5, 4.7, -4.3, -4.5, -4.7};
    int ile = 6;

    for (int i = 0; i < ile; i++)
    {
        pokazZaokraglenia(wartosci[i]);
    }

    return 0;
}
