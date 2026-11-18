// ======================================================================
// INF.04-01-26.01-SG part I - klasa Kosc (kosc.h / kosc.cpp) i jej sprawdzenie:
// dwa obiekty (konstruktor z wartością z klawiatury + bezargumentowy), po każdym:
// liczba instancji, oczka liczbą i słownie, nazwa pliku. Testy: ../KoscTesty. Spec: ../README.md
// g++ (without Visual Studio):  g++ -std=c++17 main.cpp kosc.cpp -o kosc.exe
// ======================================================================
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "kosc.h"
using namespace std;

void pokazKosc(Kosc &kosc)
{
    cout << "Liczba utworzonych kosci: " << Kosc::liczbaInstancji << endl;
    cout << "Wyrzucono: " << kosc.liczbaOczek << " (" << kosc.wartoscSlownie() << ")" << endl;
    cout << "Plik: " << kosc.nazwyPlikow[kosc.idPliku] << endl;
}

int main()
{
    srand((unsigned)time(0));

    int wartosc;
    cout << "Podaj liczbe oczek dla pierwszej kosci (1..6): ";
    cin >> wartosc;
    Kosc pierwsza(wartosc);
    pokazKosc(pierwsza);

    cout << endl << "Druga kosc (wartosc losowa):" << endl;
    Kosc druga;
    pokazKosc(druga);
    return 0;
}
