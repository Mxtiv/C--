// ======================================================================
// class splitting a 15-digit string with substr + stoi (start positions + lengths in arrays)
// Original file: unsorted/sprawdzian/MATTHEW1.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class DzielnikNapisu
{
private:
    string cyfry;   // Przechowuje 15-cyfrowy string

public:
    DzielnikNapisu(string napis)
    {
        if (napis.length() != 15)
        {
            cout << "String musi mieć dokładnie 15 cyfr! Uzywam samych zer." << endl;
            napis = "000000000000000";
        }
        cyfry = napis;
    }

    // Dzieli string na fragmenty (początek + długość z tablic) i każdy zamienia na int
    void podzielIWypisz(int poczatki[], int dlugosci[], int ile)
    {
        for (int i = 0; i < ile; i++)
        {
            int start = poczatki[i];
            int dlugosc = dlugosci[i];

            if (start >= 0 && start + dlugosc <= cyfry.length())
            {
                string fragment = cyfry.substr(start, dlugosc);
                int liczba = stoi(fragment);
                cout << "Fragment " << i + 1 << ": " << fragment << " (jako liczba: " << liczba << ")" << endl;
            }
            else
            {
                cout << "Błąd: pozycja poza zakresem!" << endl;
            }
        }
    }
};

int main()
{
    DzielnikNapisu dzielnik("123456789012345");

    const int ILE = 4;
    int poczatki[ILE] = {0, 3, 5, 10};   // pozycje początkowe fragmentów
    int dlugosci[ILE] = {3, 2, 4, 5};    // długości fragmentów

    dzielnik.podzielIWypisz(poczatki, dlugosci, ILE);

    return 0;
}
