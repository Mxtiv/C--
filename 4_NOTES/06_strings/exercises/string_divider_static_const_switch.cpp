// ======================================================================
// static const int ROZMIAR inside a class, digit = char - '0', switch
// Original file: unsorted/sprawdzian/MATTHEW3.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class DzielnikNapisu
{
private:
    static const int ROZMIAR = 15;   // stała wspólna dla klasy - może być rozmiarem tablicy
    int cyfry[ROZMIAR];              // tablica cyfr

public:
    // Konstruktor od razu zamienia string na tablicę intów
    DzielnikNapisu(string napis)
    {
        for (int i = 0; i < ROZMIAR; i++)
        {
            cyfry[i] = napis[i] - '0';   // znak cyfry -> liczba ('0' ma kod 48)
        }
    }

    // Łączy dwie cyfry z tablicy w jedną liczbę dwucyfrową
    int polaczone(int pozycja1, int pozycja2)
    {
        return cyfry[pozycja1] * 10 + cyfry[pozycja2];
    }
};

int main()
{
    DzielnikNapisu dzielnik("123456789012345");

    // Łączenie 4. i 15. cyfry (dzień miesiąca)
    int dzien = dzielnik.polaczone(3, 14);

    switch (dzien)
    {
    case 1:
        cout << "Pierwszy dzień miesiąca" << endl;
        break;
    case 15:
        cout << "Piętnasty dzień miesiąca" << endl;
        break;
    case 31:
        cout << "Ostatni dzień miesiąca (dla miesięcy z 31 dniami)" << endl;
        break;
    default:
        cout << "Dzień miesiąca: " << dzien << endl;
        break;
    }

    return 0;
}
