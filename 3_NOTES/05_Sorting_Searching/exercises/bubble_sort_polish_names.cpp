// ======================================================================
// bubble sort (Polish names)
// Original file: Arrays/Sort/bubblesort.cpp
// FIXED - the bug was: inner loop `i < j` reads tablica[i+1] one past the end on the first pass - use `i < j - 1`; correct version: 2_BUILDING_BLOCKS/04_sorting.cpp (SORT-01)
// ======================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void wypelnijLosowo(int tablica[], int rozmiarTablicy)
{
    for (int i = 0; i < rozmiarTablicy; i++)
    {
        tablica[i] = rand() % 10;
    }
}

void wypiszTablice(int tablica[], int rozmiarTablicy)
{
    for (int i = 0; i < rozmiarTablicy; i++)
    {
        cout << tablica[i] << ", ";
    }
    cout << endl;
}

void posortujBabelkowoTablice(int tablica[], int rozmiarTablicy)
{
    for (int j = rozmiarTablicy; j > 1; j--)        // j = end of the unsorted part
    {
        for (int i = 0; i < j - 1; i++)
        {
            if (tablica[i] > tablica[i + 1])
            {
                int pomocnicza = tablica[i];
                tablica[i] = tablica[i + 1];
                tablica[i + 1] = pomocnicza;
            }
        }
    }
}

int main()
{
    srand(time(0)); // ONCE, at the start of main
    const int ROZMIAR = 25;
    int tablica[ROZMIAR];
    wypelnijLosowo(tablica, ROZMIAR);
    wypiszTablice(tablica, ROZMIAR);
    posortujBabelkowoTablice(tablica, ROZMIAR);
    wypiszTablice(tablica, ROZMIAR);
    return 0;
}
