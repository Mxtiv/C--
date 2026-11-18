// ======================================================================
// insertion sort done with adjacent swaps (correct)
// Original file: Arrays/Sort/insertion.cpp
// FIXED: srand() was called inside the loop - now called once at the start of main
// ======================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void losoweLiczby(int tablica[], int rozmiarTablicy)
{
    for (int i = 0; i < rozmiarTablicy; i++)
    {
        tablica[i] = rand() % 25;
    }
}

void wypisz(int tablica[], int rozmiarTablicy)
{
    for (int i = 0; i < rozmiarTablicy; i++)
    {
        cout << tablica[i] << ", ";
    }
    cout << endl;
}

// Each new element tablica[i] "walks left" (swapping with its neighbour)
// as long as the neighbour on the left is bigger.
void sortowaniePrzezWstawianie(int tablica[], int rozmiarTablicy)
{
    for (int i = 1; i < rozmiarTablicy; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (tablica[j] < tablica[j - 1])
            {
                int pomocnicza = tablica[j];
                tablica[j] = tablica[j - 1];
                tablica[j - 1] = pomocnicza;
            }
        }
    }
}

int main()
{
    srand(time(0)); // ONCE, at the start of main
    const int ROZMIAR = 25;
    int tablica[ROZMIAR];
    losoweLiczby(tablica, ROZMIAR);
    cout << "tablica przed sortowaniem:" << endl;
    wypisz(tablica, ROZMIAR);
    sortowaniePrzezWstawianie(tablica, ROZMIAR);
    cout << "tablica po sortowaniu:" << endl;
    wypisz(tablica, ROZMIAR);

    return 0;
}
