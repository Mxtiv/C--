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
#include <iomanip>
using namespace std;

/********************************************************
 * nazwa funkcji: czyPoprawnyFormat
 * opis funkcji: sprawdza, czy napis składa się dokładnie z 11 cyfr
 * parametry: pesel - sprawdzany numer PESEL
 * zwracany typ i opis: bool - true, gdy format jest poprawny
 * autor: <numer zdającego>
 ********************************************************/
bool czyPoprawnyFormat(const string &pesel)
{
    if (pesel.length() != 11) return false;
    for (char c : pesel)
        if (!isdigit(c))
            return false;
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
bool sprawdzSumeKontrolna(const string &pesel)
{
    const int wagi[10] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int suma = 0;
    for (int i = 0; i < 10; i++)
        suma += (pesel[i] - '0') * wagi[i];
    int kontrolna = (10 - suma % 10) % 10;
    return kontrolna == pesel[10] - '0';
}

/********************************************************
 * nazwa funkcji: plec
 * opis funkcji: sprawdzana jest dziesiąta cyfra numeru PESEL (indeks 9); wartość
 *               parzysta oznacza kobietę, nieparzysta mężczyznę
 * parametry: pesel - numer PESEL
 * zwracany typ i opis: char - 'K' (kobieta) lub 'M' (mężczyzna)
 * autor: <numer zdającego>
 ********************************************************/
char plec(const string &pesel)
{
    return ((pesel[9] - '0') % 2 == 0) ? 'K' : 'M';
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
void dataUrodzenia(const string &pesel, int &dzien, int &miesiac, int &rok)
{
    rok = (pesel[0] - '0') * 10 + (pesel[1] - '0');
    miesiac = (pesel[2] - '0') * 10 + (pesel[3] - '0');
    dzien = (pesel[4] - '0') * 10 + (pesel[5] - '0');

    if (miesiac > 80)      { rok += 1800; miesiac -= 80; }
    else if (miesiac > 60) { rok += 2200; miesiac -= 60; }
    else if (miesiac > 40) { rok += 2100; miesiac -= 40; }
    else if (miesiac > 20) { rok += 2000; miesiac -= 20; }
    else                   { rok += 1900; }
}

int main()
{
    string pesel;
    cout << "Podaj numer PESEL: ";
    cin >> pesel;

    while (!czyPoprawnyFormat(pesel))
    {
        cout << "PESEL musi skladac sie z 11 cyfr. Podaj ponownie: ";
        if (!(cin >> pesel)) return 1;
    }

    if (sprawdzSumeKontrolna(pesel))
        cout << "Suma kontrolna: poprawna" << endl;
    else
        cout << "Suma kontrolna: NIEPOPRAWNA - numer PESEL jest bledny" << endl;

    cout << "Plec: " << (plec(pesel) == 'K' ? "kobieta" : "mezczyzna") << endl;

    int d, m, r;
    dataUrodzenia(pesel, d, m, r);
    cout << "Data urodzenia: " << setfill('0') << setw(2) << d << "." << setw(2) << m << "." << r << endl;
    return 0;
}
