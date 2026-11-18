// ======================================================================
// READY PROGRAM 09: Caesar cipher - encrypt / decrypt a whole line with any key,
// keeps upper/lower case, leaves spaces and other characters unchanged
// Based on: unsorted/sprawdzian/stringEncrypt.cpp (your version: lowercase only, key 3)
// Blocks used: STR-14, STR-15, IO-03, IO-05
// ======================================================================
//
// Treść zadania: Program szyfruje i odszyfrowuje tekst szyfrem Cezara. Każda litera
// jest przesuwana w alfabecie o podany klucz (po 'z' następuje 'a'). Wielkość liter
// zostaje zachowana, pozostałe znaki nie są zmieniane. Użytkownik wybiera z menu
// szyfrowanie albo odszyfrowanie, podaje tekst i klucz.

#include <iostream>
#include <string>
using namespace std;

/********************************************************
 * nazwa funkcji: szyfrujCezarem
 * opis funkcji: przesuwa każdą literę tekstu o klucz pozycji w alfabecie (z zawinięciem);
 *               wielkość liter zostaje zachowana, inne znaki się nie zmieniają
 * parametry: tekst - tekst do zaszyfrowania
 *            klucz - przesunięcie (może być ujemne)
 * zwracany typ i opis: string - zaszyfrowany tekst
 * autor: <numer zdającego>
 ********************************************************/
string szyfrujCezarem(string tekst, int klucz)
{
    klucz = klucz % 26;
    if (klucz < 0)
    {
        klucz = klucz + 26;            // e.g. -3 -> 23 (the same as 3 back)
    }

    int dlugosc = tekst.length();
    for (int i = 0; i < dlugosc; i++)
    {
        if (tekst[i] >= 'a' && tekst[i] <= 'z')
        {
            tekst[i] = 'a' + (tekst[i] - 'a' + klucz) % 26;
        }
        else if (tekst[i] >= 'A' && tekst[i] <= 'Z')
        {
            tekst[i] = 'A' + (tekst[i] - 'A' + klucz) % 26;
        }
    }
    return tekst;
}

/********************************************************
 * nazwa funkcji: deszyfrujCezarem
 * opis funkcji: odszyfrowuje tekst - przesuwa litery o klucz pozycji wstecz
 * parametry: tekst - zaszyfrowany tekst
 *            klucz - klucz użyty przy szyfrowaniu
 * zwracany typ i opis: string - odszyfrowany tekst
 * autor: <numer zdającego>
 ********************************************************/
string deszyfrujCezarem(string tekst, int klucz)
{
    return szyfrujCezarem(tekst, -klucz);
}

int main()
{
    int wybor;
    do
    {
        cout << "\n1. Szyfruj\n2. Odszyfruj\n0. Koniec\nWybierz: ";
        cin >> wybor;

        if (wybor == 1 || wybor == 2)
        {
            string tekst;
            int klucz;
            cout << "Podaj tekst: ";
            cin.ignore();
            getline(cin, tekst);
            cout << "Podaj klucz: ";
            cin >> klucz;

            if (wybor == 1)
            {
                cout << "Zaszyfrowany tekst: " << szyfrujCezarem(tekst, klucz) << endl;
            }
            else
            {
                cout << "Odszyfrowany tekst: " << deszyfrujCezarem(tekst, klucz) << endl;
            }
        }
    } while (wybor != 0);

    cout << "Koniec programu." << endl;
    return 0;
}
