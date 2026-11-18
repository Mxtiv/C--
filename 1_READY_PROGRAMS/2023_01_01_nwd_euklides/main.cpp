// ======================================================================
// INF.04-01-23.01-SG (and AG) - NWD algorytmem Euklidesa ZGODNIE ZE SCHEMATEM:
// dopóki a != b: jeśli a > b to a = a - b, w przeciwnym razie b = b - a.
// Funkcja bez wejścia/wyjścia, program główny wczytuje liczby dodatnie (z kontrolą).
// Spec + key checklist: README.md in this folder.
// ======================================================================
#include <iostream>
using namespace std;

/**********************************************
nazwa funkcji:  nwd
opis funkcji:   wyznacza największy wspólny dzielnik dwóch liczb algorytmem Euklidesa
                (wersja z odejmowaniem)
parametry:      a - pierwsza liczba całkowita dodatnia
                b - druga liczba całkowita dodatnia
zwracany typ i opis: int - największy wspólny dzielnik liczb a i b
autor:          00000000000
***********************************************/
int nwd(int a, int b)
{
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    return a;
}

int wczytajDodatnia(const char *komunikat)
{
    int liczba;
    cout << komunikat;
    while (!(cin >> liczba) || liczba <= 0)
    {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "To nie jest liczba calkowita dodatnia. Podaj ponownie: ";
    }
    return liczba;
}

int main()
{
    int a = wczytajDodatnia("Podaj liczbe a: ");
    int b = wczytajDodatnia("Podaj liczbe b: ");
    cout << "NWD(" << a << ", " << b << ") = " << nwd(a, b) << endl;
    return 0;
}
