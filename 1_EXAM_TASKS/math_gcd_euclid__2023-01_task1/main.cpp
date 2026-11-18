// ======================================================================
// INF.04-01-23.01-SG (and AG) - NWD algorytmem Euklidesa ZGODNIE ZE SCHEMATEM:
// dopóki a != b: jeśli a > b to a = a - b, w przeciwnym razie b = b - a.
// Funkcja bez wejścia/wyjścia, program główny wczytuje liczby dodatnie (pętla do-while
// pyta ponownie, dopóki liczba nie jest dodatnia).
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

int main()
{
    int a;
    do
    {
        cout << "Podaj liczbe calkowita dodatnia a: ";
        cin >> a;
    } while (a <= 0);

    int b;
    do
    {
        cout << "Podaj liczbe calkowita dodatnia b: ";
        cin >> b;
    } while (b <= 0);

    cout << "NWD(" << a << ", " << b << ") = " << nwd(a, b) << endl;
    return 0;
}
