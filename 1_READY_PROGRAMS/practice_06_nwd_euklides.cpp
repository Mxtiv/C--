// ======================================================================
// READY PROGRAM 06: NWD (GCD) by Euclid - subtraction AND modulo versions - and NWW (LCM)
// Original file: inf04/5)Euklides.cpp
// Blocks used: NUM-05, NUM-04, NUM-07, IO-01
// ======================================================================
//
// Treść zadania: Program pobiera dwie liczby naturalne dodatnie i wyznacza ich
// największy wspólny dzielnik algorytmem Euklidesa w wersji z odejmowaniem
// (dopóki liczby są różne, od większej odejmujemy mniejszą) oraz najmniejszą
// wspólną wielokrotność NWW(a, b) = a * b / NWD(a, b).

#include <iostream>
#include <string>
#include <limits>
using namespace std;

/********************************************************
 * nazwa funkcji: nwdOdejmowanie
 * opis funkcji: wyznacza NWD dwóch liczb algorytmem Euklidesa z odejmowaniem -
 *               dopóki liczby są różne, od większej odejmuje się mniejszą
 * parametry: a - pierwsza liczba dodatnia
 *            b - druga liczba dodatnia
 * zwracany typ i opis: int - największy wspólny dzielnik
 * autor: <numer zdającego>
 ********************************************************/
int nwdOdejmowanie(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

/********************************************************
 * nazwa funkcji: nwdModulo
 * opis funkcji: wyznacza NWD dwóch liczb algorytmem Euklidesa z resztą z dzielenia
 * parametry: a - pierwsza liczba
 *            b - druga liczba
 * zwracany typ i opis: int - największy wspólny dzielnik
 * autor: <numer zdającego>
 ********************************************************/
int nwdModulo(int a, int b)
{
    while (b != 0)
    {
        int reszta = a % b;
        a = b;
        b = reszta;
    }
    return a;
}

/********************************************************
 * nazwa funkcji: nww
 * opis funkcji: wyznacza najmniejszą wspólną wielokrotność dwóch liczb
 * parametry: a - pierwsza liczba
 *            b - druga liczba
 * zwracany typ i opis: long long - najmniejsza wspólna wielokrotność
 * autor: <numer zdającego>
 ********************************************************/
long long nww(int a, int b)
{
    return (long long)a / nwdModulo(a, b) * b;
}

/********************************************************
 * nazwa funkcji: wczytajLiczbe
 * opis funkcji: wczytuje liczbę całkowitą z zakresu min..max, ponawiając pytanie przy błędzie
 * parametry: komunikat - tekst wyświetlany użytkownikowi
 *            min - najmniejsza dopuszczalna wartość
 *            max - największa dopuszczalna wartość
 * zwracany typ i opis: int - poprawna liczba
 * autor: <numer zdającego>
 ********************************************************/
int wczytajLiczbe(const string &komunikat, int min, int max)
{
    int liczba;
    while (true)
    {
        cout << komunikat;
        if (cin >> liczba && liczba >= min && liczba <= max)
            return liczba;
        cout << "Podaj liczbe od " << min << " do " << max << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main()
{
    int a = wczytajLiczbe("Podaj pierwsza liczbe dodatnia: ", 1, 1000000);
    int b = wczytajLiczbe("Podaj druga liczbe dodatnia: ", 1, 1000000);

    cout << "NWD(" << a << ", " << b << ") metoda odejmowania = " << nwdOdejmowanie(a, b) << endl;
    cout << "NWD(" << a << ", " << b << ") metoda z reszta    = " << nwdModulo(a, b) << endl;
    cout << "NWW(" << a << ", " << b << ") = " << nww(a, b) << endl;
    return 0;
}
