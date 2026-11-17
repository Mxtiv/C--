// ======================================================================
// bubble sort (Polish names)
// Original file: Arrays/Sort/bubblesort.cpp
// FIXED - the bug was: inner loop `i < j` reads tablica[i+1] one past the end on the first pass - use `i < j - 1`; correct version: 2_BUILDING_BLOCKS/04_sorting.cpp (SORT-01)
// ======================================================================

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
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
}
void posortujBabelkowoTablice(int tablica[], int rozmiarTablicy)
{
    for(int j = rozmiarTablicy; j!=1; j--)
    {
        for (int i = 0; i < j - 1; i++)
        {
            if(tablica[i] > tablica[i+1])
            {
                int temp = tablica[i];
                tablica[i] = tablica[i+1];
                tablica[i+1] = temp;
            }
        }
    }
}
int main()
{
    srand(time(NULL)); // ONCE, at the start of main
    int table[25];
    wypelnijLosowo(table, 25);
    wypiszTablice(table, 25);
    cout << endl;
    posortujBabelkowoTablice(table, 25);
    wypiszTablice(table, 25);
}