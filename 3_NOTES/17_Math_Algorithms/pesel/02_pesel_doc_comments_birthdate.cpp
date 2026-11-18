// ======================================================================
// "long" version: checksum written out digit by digit (no weights array),
// if M == 0 then R = 0 else R = 10 - M, input check (11 characters, all digits)
// Original file: Arrays/pesel.cpp
// FIXED - the bug was: weight for digit 2 is 2 - must be 3 (1,3,7,9,1,3,7,9,1,3)
// ======================================================================

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/********************************************************
 * nazwa funkcji: czyPoprawnyFormat
 * opis funkcji: sprawdza, czy napis ma 11 znakow i same cyfry
 * parametry: pesel - napis do sprawdzenia
 * zwracany typ i opis: bool - true gdy 11 cyfr
 * autor: <numer zdającego>
 ********************************************************/
bool czyPoprawnyFormat(string pesel)
{
    if (pesel.length() != 11)
    {
        return false;
    }
    for (int i = 0; i < 11; i++)
    {
        if (!isdigit(pesel[i]))
        {
            return false;
        }
    }
    return true;
}

/********************************************************
 * nazwa funkcji: sumaKontrolna
 * opis funkcji: liczy sume kontrolna (wagi 1 3 7 9 1 3 7 9 1 3) i porownuje z cyfra nr 10
 * parametry: pesel - numer PESEL (11 cyfr)
 * zwracany typ i opis: bool - true gdy PESEL zgodny z suma kontrolna
 * autor: <numer zdającego>
 ********************************************************/
bool sumaKontrolna(string pesel)
{
    int s = (pesel[0] - '0') * 1 + (pesel[1] - '0') * 3 + (pesel[2] - '0') * 7 + (pesel[3] - '0') * 9
          + (pesel[4] - '0') * 1 + (pesel[5] - '0') * 3 + (pesel[6] - '0') * 7 + (pesel[7] - '0') * 9
          + (pesel[8] - '0') * 1 + (pesel[9] - '0') * 3;

    int m = s % 10;
    int r;
    if (m == 0)
    {
        r = 0;
    }
    else
    {
        r = 10 - m;
    }

    if (r == pesel[10] - '0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string pesel;
    do
    {
        cout << "Podaj PESEL (11 cyfr): ";
        cin >> pesel;
    } while (!czyPoprawnyFormat(pesel));

    if ((pesel[9] - '0') % 2 == 0)
    {
        cout << "Jestes kobieta" << endl;
    }
    else
    {
        cout << "Jestes mezczyzna" << endl;
    }

    if (sumaKontrolna(pesel))
    {
        cout << "PESEL zgodny z suma kontrolna" << endl;
    }
    else
    {
        cout << "PESEL niezgodny z suma kontrolna" << endl;
    }

    // data urodzenia - tylko lata 1900 i 2000 (miesiac 21-32 = rok 20xx)
    int miesiac = (pesel[2] - '0') * 10 + (pesel[3] - '0');
    if (miesiac > 20)
    {
        cout << "Rok urodzenia: 20" << pesel[0] << pesel[1] << endl;
        miesiac = miesiac - 20;
    }
    else
    {
        cout << "Rok urodzenia: 19" << pesel[0] << pesel[1] << endl;
    }
    cout << "Miesiac: " << miesiac << endl;
    cout << "Dzien: " << pesel[4] << pesel[5] << endl;

    return 0;
}
