// ======================================================================
// random fill + min/max element functions
// Original file: Arrays/Sort/sortowanie.cpp
// FIXED - the bug was: srand() inside the loop - call srand(time(0)) ONCE at the start of main
// ======================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void wypelnijLosowo(int tablica[], int rozmiarTablicy)
{
    for (int i = 0; i < rozmiarTablicy; i++)   // wypełnianie tablicy losowymi cyframi
    {
        tablica[i] = rand() % 10;              // wstawiamy do i-tego elementu losową cyfrę
    }
}

void wypiszTablice(int tablica[], int rozmiarTablicy)
{
    for (int i = 0; i < rozmiarTablicy; i++)   // wypisujemy wszystkie elementy z przecinkami
    {
        cout << tablica[i] << ", ";
    }
    cout << endl;
}

int elementMinimalny(int tablica[], int rozmiarTablicy)
{
    int min = tablica[0];
    for (int i = 1; i < rozmiarTablicy; i++)   // szukamy najmniejszej wartości
    {
        if (tablica[i] < min)
        {
            min = tablica[i];
        }
    }
    return min;
}

int elementMaksymalny(int tablica[], int rozmiarTablicy)
{
    int max = tablica[0];
    for (int i = 1; i < rozmiarTablicy; i++)   // szukamy największej wartości
    {
        if (tablica[i] > max)
        {
            max = tablica[i];
        }
    }
    return max;
}

int main()
{
    srand(time(0)); // ONCE, at the start of main
    const int ROZMIAR = 10;
    int liczby[ROZMIAR];
    wypelnijLosowo(liczby, ROZMIAR);
    wypiszTablice(liczby, ROZMIAR);
    cout << "max: " << elementMaksymalny(liczby, ROZMIAR) << endl;
    cout << "min: " << elementMinimalny(liczby, ROZMIAR) << endl;
    return 0;
}
