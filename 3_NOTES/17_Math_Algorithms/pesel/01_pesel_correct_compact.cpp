// ======================================================================
// CORRECT PESEL: weights array, (10 - S % 10) % 10, - '0', century from month (+80/+20)
// Original file: unsorted/calculations/peselBirthSexKMAK.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

/********************************************************
 * nazwa funkcji: plec
 * opis funkcji: cyfra nr 9 (dziesiata) - parzysta = kobieta, nieparzysta = mezczyzna
 * parametry: pesel - numer PESEL (11 cyfr)
 * zwracany typ i opis: char - 'K' kobieta lub 'M' mezczyzna
 * autor: <numer zdającego>
 ********************************************************/
char plec(string pesel)
{
    int cyfra = pesel[9] - '0';        // - '0' zamienia znak cyfry na liczbe
    if (cyfra % 2 == 0)
    {
        return 'K';
    }
    else
    {
        return 'M';
    }
}

/********************************************************
 * nazwa funkcji: sumaKontrolna
 * opis funkcji: S = suma cyfra*waga dla cyfr 0..9, R = (10 - S % 10) % 10,
 *               PESEL poprawny, gdy R == cyfra nr 10
 * parametry: pesel - numer PESEL (11 cyfr)
 * zwracany typ i opis: bool - true gdy suma kontrolna sie zgadza
 * autor: <numer zdającego>
 ********************************************************/
bool sumaKontrolna(string pesel)
{
    int wagi[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int s = 0;
    for (int i = 0; i < 10; i++)
    {
        s = s + (pesel[i] - '0') * wagi[i];
    }
    int r = (10 - s % 10) % 10;
    if (r == pesel[10] - '0')
    {
        return true;
    }
    else
    {
        return false;
    }
}

/********************************************************
 * nazwa funkcji: dataUrodzenia
 * opis funkcji: wypisuje date urodzenia; miesiac +80 -> lata 1800, +20 -> lata 2000
 * parametry: pesel - numer PESEL (11 cyfr)
 * zwracany typ i opis: brak
 * autor: <numer zdającego>
 ********************************************************/
void dataUrodzenia(string pesel)
{
    int rok = (pesel[0] - '0') * 10 + (pesel[1] - '0');
    int miesiac = (pesel[2] - '0') * 10 + (pesel[3] - '0');
    int dzien = (pesel[4] - '0') * 10 + (pesel[5] - '0');

    if (miesiac > 80)
    {
        rok = rok + 1800;
        miesiac = miesiac - 80;
    }
    else if (miesiac > 20)
    {
        rok = rok + 2000;
        miesiac = miesiac - 20;
    }
    else
    {
        rok = rok + 1900;
    }

    cout << "Data urodzenia: " << dzien << "-" << miesiac << "-" << rok << endl;
}

int main()
{
    string pesel;
    do
    {
        cout << "Podaj PESEL (11 cyfr): ";
        cin >> pesel;
    } while (pesel.length() != 11);

    if (plec(pesel) == 'K')
    {
        cout << "Plec: kobieta" << endl;
    }
    else
    {
        cout << "Plec: mezczyzna" << endl;
    }

    dataUrodzenia(pesel);

    if (sumaKontrolna(pesel))
    {
        cout << "PESEL poprawny" << endl;
    }
    else
    {
        cout << "PESEL niepoprawny" << endl;
    }

    return 0;
}
