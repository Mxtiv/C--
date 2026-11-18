#include "szyfr.h"

/**********************************************
nazwa funkcji:  szyfruj
opis funkcji:   szyfruje tekst szyfrem Cezara - każdą małą literę a-z przesuwa w alfabecie
                o klucz pozycji (z zawijaniem z) -> a), spacja zostaje bez zmian
parametry:      tekst - tekst jawny (małe litery i spacje)
                klucz - przesunięcie, dowolna liczba całkowita (ujemna, większa od 26)
zwracany typ i opis: string - tekst zaszyfrowany
autor:          00000000000
***********************************************/
string szyfruj(string tekst, int klucz)
{
    int przesuniecie = klucz % 26;                 // 29 -> 3, -29 -> -3
    if (przesuniecie < 0)
    {
        przesuniecie = przesuniecie + 26;          // -3 -> 23 (to samo co 3 w lewo)
    }

    string wynik = "";
    int dlugosc = tekst.length();
    for (int i = 0; i < dlugosc; i++)
    {
        char znak = tekst[i];
        if (znak >= 'a' && znak <= 'z')            // kody ASCII 97..122
        {
            wynik += (char)('a' + (znak - 'a' + przesuniecie) % 26);
        }
        else
        {
            wynik += znak;                          // spacja (i inne znaki) bez zmian
        }
    }
    return wynik;
}
