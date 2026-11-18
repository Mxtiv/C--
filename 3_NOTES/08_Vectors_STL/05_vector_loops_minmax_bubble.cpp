// ======================================================================
// vector<int> wektor(n) used like an array, everything in main:
// for / while loops, min/max/sum/avg, bubble sort
// Original file: Arrays/vectors/vectorsLoops.cpp
// ======================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    int n;
    do
    {
        cout << "Enter number of elements (1-50): ";
        cin >> n;
    } while (n < 1 || n > 50);

    vector<int> wektor(n);      // n elements at once (all 0) - then use wektor[i] like an array

    for (int i = 0; i < n; i++)
    {
        wektor[i] = rand() % 100;
    }

    cout << "Vector elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << wektor[i] << " ";
    }
    cout << endl;

    int min = wektor[0];
    int max = wektor[0];
    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        if (wektor[i] < min)
        {
            min = wektor[i];
        }
        if (wektor[i] > max)
        {
            max = wektor[i];
        }
        suma = suma + wektor[i];
    }
    double srednia = (double)suma / n;

    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Sum: " << suma << endl;
    cout << "Average: " << srednia << endl;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (wektor[j] > wektor[j + 1])
            {
                int pomocnicza = wektor[j];
                wektor[j] = wektor[j + 1];
                wektor[j + 1] = pomocnicza;
            }
        }
    }

    cout << "Sorted vector (while loop): ";
    int indeks = 0;
    while (indeks < n)
    {
        cout << wektor[indeks] << " ";
        indeks++;
    }
    cout << endl;

    return 0;
}
