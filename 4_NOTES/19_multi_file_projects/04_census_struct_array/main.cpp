// ======================================================================
// census: struct array via new, search by name/age, do-while menu, switch with random goodbye
// Original file: unsorted/spisLudnosci/main.cpp
// Build: g++ main.cpp census.cpp -o census.exe
// ======================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "census.h"
using namespace std;

int main()
{
    srand(time(0));

    int rozmiar;
    do
    {
        cout << "Ilu obywateli wprowadzic (1-100): ";
        cin >> rozmiar;
    } while (rozmiar < 1 || rozmiar > 100);

    Obywatel *tablica = utworzTablice(rozmiar);
    pobierzDane(tablica, rozmiar);

    char wybor;
    do
    {
        cout << "Szukac po imieniu (a) czy po wieku (b)? ";
        cin >> wybor;

        if (wybor == 'a')
        {
            string imie;
            cout << "Podaj imie: ";
            cin >> imie;
            szukajPoImieniu(tablica, rozmiar, imie);
        }
        else if (wybor == 'b')
        {
            int wiek;
            cout << "Podaj wiek: ";
            cin >> wiek;
            szukajPoWieku(tablica, rozmiar, wiek);
        }
        else
        {
            cout << "Nieznana opcja." << endl;
        }

        cout << "Szukac ponownie? (t/n): ";
        cin >> wybor;
    } while (wybor == 't' || wybor == 'T');

    // losowe pozegnanie
    int numer = rand() % 3 + 1;
    switch (numer)
    {
    case 1:
        cout << "Do widzenia!" << endl;
        break;
    case 2:
        cout << "Goodbye!" << endl;
        break;
    case 3:
        cout << "Auf Wiedersehen!" << endl;
        break;
    }

    usunTablice(tablica);
    return 0;
}
