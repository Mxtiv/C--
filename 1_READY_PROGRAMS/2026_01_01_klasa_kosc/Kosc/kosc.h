// Klasa Kosc - deklaracja (implementacja w kosc.cpp). Osobny plik .h = można jej użyć w testach.
#pragma once
#include <string>

/******************************************************
nazwa klasy: Kosc
opis: pojedyncza kość do gry (wartości 1..6) z nazwą pliku graficznego dla wyniku
pola: liczbaInstancji - (statyczne) liczba utworzonych obiektów klasy
      nazwyPlikow - nazwy plików kosc0.png ... kosc6.png
      liczbaOczek - wartość wyrzucona kością
      idPliku - indeks w nazwyPlikow odpowiadający wyrzuconej wartości
      dostepna - czy kość bierze udział w rzucie
autor: 00000000000
*****************************************************/
class Kosc
{
public:
    static int liczbaInstancji;
    std::string nazwyPlikow[7] = {"kosc0.png", "kosc1.png", "kosc2.png", "kosc3.png",
                                  "kosc4.png", "kosc5.png", "kosc6.png"};
    int liczbaOczek;
    int idPliku;
    bool dostepna;

    Kosc(int wartosc);
    Kosc();
    void rzuc();
    void zablokuj();
    std::string wartoscSlownie();
};
