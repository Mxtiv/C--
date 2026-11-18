// ======================================================================
// selection sort + count divisible by 3
// Original file: unsorted/various/selectionsort.cpp
// FIXED - the bug was: DOES NOT COMPILE: podzielnePrzezTrzy(tablica) is missing the size argument
// ======================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Find the smallest element of the unsorted part and swap it to position i
void sortowaniePrzezWybieranie(int tablica[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int indeksMin = i;
        for (int j = i + 1; j < n; j++)
        {
            if (tablica[j] < tablica[indeksMin])
            {
                indeksMin = j;
            }
        }
        int pomocnicza = tablica[i];
        tablica[i] = tablica[indeksMin];
        tablica[indeksMin] = pomocnicza;
    }
}

int podzielnePrzezTrzy(int tablica[], int n)
{
    int liczbaPodzielnych = 0;
    for (int i = 0; i < n; i++)
    {
        if (tablica[i] % 3 == 0)
        {
            liczbaPodzielnych++;
        }
    }
    return liczbaPodzielnych;
}

void wypisz(int tablica[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << tablica[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(0));
    const int ROZMIAR = 10;
    int tablica[ROZMIAR];

    for (int i = 0; i < ROZMIAR; i++)
    {
        tablica[i] = rand() % 11 + 10;
    }

    cout << "Zawartosc tablicy przed sortowaniem: ";
    wypisz(tablica, ROZMIAR);

    sortowaniePrzezWybieranie(tablica, ROZMIAR);

    cout << "Po sortowaniu: ";
    wypisz(tablica, ROZMIAR);
    cout << "Podzielnych przez 3: " << podzielnePrzezTrzy(tablica, ROZMIAR) << endl;

    return 0;
}
