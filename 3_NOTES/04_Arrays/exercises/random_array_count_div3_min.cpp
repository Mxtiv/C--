// ======================================================================
// const size array, random 10-20, count divisible by 3, minimum
// Original file: unsorted/various/podzielneprzez333.cpp
// FIXED: srand() was called inside the loop - now called once at the start of main
// ======================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void losowanie(int tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        tab[i] = rand() % 11 + 10;      // 10..20
    }
}

void wypisz(int tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << ", ";
    }
}

int liczbaPodzielnychPrzezTrzy(int tab[], int n)
{
    int liczbaPodzielnych = 0;
    for (int i = 0; i < n; i++)
    {
        if (tab[i] % 3 == 0)
        {
            liczbaPodzielnych++;
        }
    }
    return liczbaPodzielnych;
}

int elementMinimalny(int tab[], int n)
{
    int min = tab[0];
    for (int i = 1; i < n; i++)
    {
        if (tab[i] < min)
        {
            min = tab[i];
        }
    }
    return min;
}

int main()
{
    srand(time(0)); // ONCE, at the start of main
    const int ROZMIAR = 11;
    int tab[ROZMIAR];
    losowanie(tab, ROZMIAR);
    wypisz(tab, ROZMIAR);
    cout << "\nIlosc liczb podzielnych przez 3: " << liczbaPodzielnychPrzezTrzy(tab, ROZMIAR);
    cout << "\nElement minimalny to: " << elementMinimalny(tab, ROZMIAR) << endl;
    return 0;
}
