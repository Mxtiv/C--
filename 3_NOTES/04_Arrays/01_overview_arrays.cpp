// ======================================================================
// static + dynamic arrays: random fill, print, min, max, sum, average,
// array + count (collecting results into a second array), bubble sort
// Original file: Arrays/overviewArrays.cpp
// ======================================================================

#include <iostream>
#include <cstdlib>  // rand, srand
#include <ctime>    // time
using namespace std;

// INDEX PIERWSZY TABLICY TO ZERO !!!!!!!!!!!!!!!!!!!!!!!!!!!
// int tab[10] -> elements tab[0] .. tab[9]. tab[10] does NOT exist.

// Fill an array with random numbers 0-99.
// An array passed to a function is the ORIGINAL (not a copy) - so it can be filled here.
void wypelnijLosowo(int tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        tab[i] = rand() % 100;
    }
}

void wypisz(int tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;
}

int znajdzMin(int tab[], int n)
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

int znajdzMax(int tab[], int n)
{
    int max = tab[0];
    for (int i = 1; i < n; i++)
    {
        if (tab[i] > max)
        {
            max = tab[i];
        }
    }
    return max;
}

int suma(int tab[], int n)
{
    int wynik = 0;
    for (int i = 0; i < n; i++)
    {
        wynik = wynik + tab[i];
    }
    return wynik;
}

double srednia(int tab[], int n)
{
    return (double)suma(tab, n) / n;     // cast, otherwise integer division
}

// Copies the even numbers into wynik[] and RETURNS how many there are
int parzyste(int tab[], int n, int wynik[])
{
    int ile = 0;
    for (int i = 0; i < n; i++)
    {
        if (tab[i] % 2 == 0)
        {
            wynik[ile] = tab[i];
            ile++;
        }
    }
    return ile;
}

void sortowanieBabelkowe(int tab[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                int pomocnicza = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = pomocnicza;
            }
        }
    }
}

int main()
{
    srand(time(0));

    // ---------------- static array: size is a constant ----------------
    const int ROZMIAR = 10;
    int tablica[ROZMIAR];
    wypelnijLosowo(tablica, ROZMIAR);

    cout << "Static array: ";
    wypisz(tablica, ROZMIAR);
    cout << "Min: " << znajdzMin(tablica, ROZMIAR) << endl;
    cout << "Max: " << znajdzMax(tablica, ROZMIAR) << endl;
    cout << "Sum: " << suma(tablica, ROZMIAR) << endl;
    cout << "Average: " << srednia(tablica, ROZMIAR) << endl;

    // ---------------- array + count: many results go to a second array ----------------
    int tylkoParzyste[ROZMIAR];
    int ileParzystych = parzyste(tablica, ROZMIAR, tylkoParzyste);
    cout << "Even numbers (" << ileParzystych << "): ";
    wypisz(tylkoParzyste, ileParzystych);

    sortowanieBabelkowe(tablica, ROZMIAR);
    cout << "Sorted: ";
    wypisz(tablica, ROZMIAR);

    // ---------------- dynamic array: size known only while the program runs ----------------
    int rozmiar;
    do
    {
        cout << "\nEnter size for dynamic array (1-50): ";
        cin >> rozmiar;
    } while (rozmiar < 1 || rozmiar > 50);

    int *dynamiczna = new int[rozmiar];      // the same functions work for it
    wypelnijLosowo(dynamiczna, rozmiar);
    cout << "Dynamic array: ";
    wypisz(dynamiczna, rozmiar);
    cout << "Min: " << znajdzMin(dynamiczna, rozmiar) << ", Max: " << znajdzMax(dynamiczna, rozmiar) << endl;

    delete[] dynamiczna;                     // every new[] needs its delete[]
    return 0;
}
