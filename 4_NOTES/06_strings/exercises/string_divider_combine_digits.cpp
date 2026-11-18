// ======================================================================
// combine chosen digits: wynik = wynik + tekst.substr(pozycja, 1); stoi
// Original file: unsorted/sprawdzian/MATTHEW2.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class DzielnikNapisu
{
private:
    string cyfry;   // Przechowuje 15-cyfrowy string

public:
    // Konstruktor przyjmujący 15-cyfrowy string
    DzielnikNapisu(string napis)
    {
        if (napis.length() != 15)
        {
            cout << "String musi mieć dokładnie 15 cyfr! Uzywam samych zer." << endl;
            napis = "000000000000000";
        }
        cyfry = napis;
    }

    // Przyjmuje tablicę pozycji cyfr i zwraca połączone cyfry jako int
    int polaczone(int pozycje[], int ile)
    {
        string wynik = "";
        for (int i = 0; i < ile; i++)
        {
            int pozycja = pozycje[i];
            if (pozycja >= 0 && pozycja < cyfry.length())
            {
                wynik = wynik + cyfry.substr(pozycja, 1);   // pobranie jednej cyfry
            }
            else
            {
                cout << "Pozycja " << pozycja << " poza zakresem!" << endl;
            }
        }
        if (wynik == "")
        {
            return 0;
        }
        return stoi(wynik);   // konwersja połączonych cyfr na int
    }
};

int main()
{
    DzielnikNapisu dzielnik("123456789012345");   // przykładowy 15-cyfrowy string

    // 4. i 15. cyfra
    int pozycje1[2] = {3, 14};
    cout << "Połączone cyfry z pozycji 4 i 15: " << dzielnik.polaczone(pozycje1, 2) << endl;

    // 1., 2., 5. i 10. cyfra
    int pozycje2[4] = {0, 1, 4, 9};
    cout << "Połączone cyfry z pozycji 1, 2, 5 i 10: " << dzielnik.polaczone(pozycje2, 4) << endl;

    return 0;
}
