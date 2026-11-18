// ======================================================================
// for / while / do-while over an array and a vector; min/max/sum/avg; bubble sort
// Original file: Arrays/arraysLoops.cpp
// ======================================================================

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // ----- FOR LOOP WITH ARRAY -----
    const int ROZMIAR = 5;
    int tab[ROZMIAR] = {10, 20, 30, 40, 50};

    cout << "For loop over array:" << endl;
    for (int i = 0; i < ROZMIAR; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl;

    // ----- WHILE LOOP WITH ARRAY -----
    cout << "While loop over array:" << endl;
    int indeks = 0;
    while (indeks < ROZMIAR)
    {
        cout << tab[indeks] << " ";
        indeks++;
    }
    cout << endl;

    // ----- DO-WHILE LOOP WITH ARRAY -----
    cout << "Do-while loop over array:" << endl;
    indeks = 0;
    do
    {
        cout << tab[indeks] << " ";
        indeks++;
    } while (indeks < ROZMIAR);
    cout << endl;

    // ----- LOOP OVER A VECTOR (the same index loop, size comes from .size()) -----
    vector<int> wektor;
    wektor.push_back(5);
    wektor.push_back(10);
    wektor.push_back(15);

    cout << "For loop over vector:" << endl;
    for (int i = 0; i < wektor.size(); i++)
    {
        cout << wektor[i] << " ";
    }
    cout << endl;

    // ----- MIN, MAX, SUM, AVERAGE IN ARRAY -----
    int min = tab[0];
    int max = tab[0];
    int suma = 0;
    for (int i = 0; i < ROZMIAR; i++)
    {
        if (tab[i] < min)
        {
            min = tab[i];
        }
        if (tab[i] > max)
        {
            max = tab[i];
        }
        suma = suma + tab[i];
    }
    double srednia = (double)suma / ROZMIAR;
    cout << "Min: " << min << ", Max: " << max << ", Sum: " << suma << ", Avg: " << srednia << endl;

    // ----- SORTING AN ARRAY (Bubble Sort) -----
    int doSortowania[ROZMIAR] = {10, 5, 30, 20, 15};
    for (int i = 0; i < ROZMIAR - 1; i++)
    {
        for (int j = 0; j < ROZMIAR - i - 1; j++)
        {
            if (doSortowania[j] > doSortowania[j + 1])
            {
                int pomocnicza = doSortowania[j];
                doSortowania[j] = doSortowania[j + 1];
                doSortowania[j + 1] = pomocnicza;
            }
        }
    }
    cout << "Sorted array: ";
    for (int i = 0; i < ROZMIAR; i++)
    {
        cout << doSortowania[i] << " ";
    }
    cout << endl;

    return 0;
}
