// ======================================================================
// READY PROGRAM 04: PESEL checker - format, control digit, sex, birth date
// Original file: inf04/3)Pesel.cpp
// Blocks used: PESEL-01, PESEL-03, PESEL-04, PESEL-05
// ======================================================================
//
// Treść zadania: Program pobiera numer PESEL, sprawdza jego poprawność (11 cyfr oraz
// cyfra kontrolna liczona z wagami 1 3 7 9 1 3 7 9 1 3), określa płeć (dziesiąta
// cyfra: parzysta - kobieta, nieparzysta - mężczyzna) oraz datę urodzenia.
// Funkcja określająca płeć zwraca 'K' albo 'M'; funkcja sprawdzająca sumę
// kontrolną zwraca wartość logiczną.

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/********************************************************
 * nazwa funkcji: czyPoprawnyFormat
 * opis funkcji: sprawdza, czy napis składa się dokładnie z 11 cyfr
 * parametry: pesel - sprawdzany numer PESEL
 * zwracany typ i opis: bool - true, gdy format jest poprawny
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
 * nazwa funkcji: sprawdzSumeKontrolna
 * opis funkcji: oblicza sumę iloczynów pierwszych 10 cyfr i wag 1 3 7 9 1 3 7 9 1 3;
 *               cyfra kontrolna = (10 - suma % 10) % 10 i porównuje ją z ostatnią cyfrą
 * parametry: pesel - numer PESEL (11 cyfr)
 * zwracany typ i opis: bool - true, gdy suma kontrolna jest zgodna
 * autor: <numer zdającego>
 ********************************************************/
bool sprawdzSumeKontrolna(string pesel)
{
    int wagi[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int suma = 0;
    for (int i = 0; i < 10; i++)
    {
        suma = suma + (pesel[i] - '0') * wagi[i];
    }
    int kontrolna = (10 - suma % 10) % 10;
    if (kontrolna == pesel[10] - '0')
    {
        return true;
    }
    return false;
}

/********************************************************
 * nazwa funkcji: plec
 * opis funkcji: sprawdzana jest dziesiąta cyfra numeru PESEL (indeks 9); wartość
 *               parzysta oznacza kobietę, nieparzysta mężczyznę
 * parametry: pesel - numer PESEL
 * zwracany typ i opis: char - 'K' (kobieta) lub 'M' (mężczyzna)
 * autor: <numer zdającego>
 ********************************************************/
char plec(string pesel)
{
    if ((pesel[9] - '0') % 2 == 0)
    {
        return 'K';
    }
    return 'M';
}

/********************************************************
 * nazwa funkcji: dataUrodzenia
 * opis funkcji: odczytuje datę urodzenia; stulecie wynika z dodatku do miesiąca
 *               (+80: 1800, +0: 1900, +20: 2000, +40: 2100, +60: 2200)
 * parametry: pesel - numer PESEL
 *            dzien, miesiac, rok - (wyjście) data urodzenia
 * zwracany typ i opis: brak (wyniki przez parametry referencyjne)
 * autor: <numer zdającego>
 ********************************************************/
void dataUrodzenia(string pesel, int &dzien, int &miesiac, int &rok)
{
    rok = (pesel[0] - '0') * 10 + (pesel[1] - '0');
    miesiac = (pesel[2] - '0') * 10 + (pesel[3] - '0');
    dzien = (pesel[4] - '0') * 10 + (pesel[5] - '0');

    if (miesiac > 80)
    {
        rok = rok + 1800;
        miesiac = miesiac - 80;
    }
    else if (miesiac > 60)
    {
        rok = rok + 2200;
        miesiac = miesiac - 60;
    }
    else if (miesiac > 40)
    {
        rok = rok + 2100;
        miesiac = miesiac - 40;
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
}

int main()
{
    string pesel;
    do
    {
        cout << "Podaj numer PESEL (11 cyfr): ";
        cin >> pesel;
    } while (!czyPoprawnyFormat(pesel));

    if (sprawdzSumeKontrolna(pesel))
    {
        cout << "Suma kontrolna: poprawna" << endl;
    }
    else
    {
        cout << "Suma kontrolna: NIEPOPRAWNA - numer PESEL jest bledny" << endl;
    }

    if (plec(pesel) == 'K')
    {
        cout << "Plec: kobieta" << endl;
    }
    else
    {
        cout << "Plec: mezczyzna" << endl;
    }

    int d, m, r;
    dataUrodzenia(pesel, d, m, r);
    cout << "Data urodzenia: ";
    if (d < 10)
    {
        cout << "0";
    }
    cout << d << ".";
    if (m < 10)
    {
        cout << "0";
    }
    cout << m << "." << r << endl;
    return 0;
}
