// ======================================================================
// vector in functions: fill with push_back, print, min, max, sum, average, bubble sort
// Original file: Arrays/vectors/overviewVectors.cpp
// ======================================================================

#include <iostream>
#include <vector>
#include <cstdlib>   // rand, srand
#include <ctime>     // time
using namespace std;

// & - the function ADDS elements, so it must work on the caller's vector
// (without & it would fill a copy and the caller's vector would stay empty)
void wypelnijLosowo(vector<int> &wektor, int ile, int min, int max)
{
    wektor.clear();
    for (int i = 0; i < ile; i++)
    {
        wektor.push_back(rand() % (max - min + 1) + min);
    }
}

// by value - the function only reads the vector; .size() says how many elements it has
void wypisz(vector<int> wektor)
{
    for (int i = 0; i < wektor.size(); i++)
    {
        cout << wektor[i] << " ";
    }
    cout << endl;
}

int znajdzMin(vector<int> wektor)
{
    int min = wektor[0];
    for (int i = 1; i < wektor.size(); i++)
    {
        if (wektor[i] < min)
        {
            min = wektor[i];
        }
    }
    return min;
}

int znajdzMax(vector<int> wektor)
{
    int max = wektor[0];
    for (int i = 1; i < wektor.size(); i++)
    {
        if (wektor[i] > max)
        {
            max = wektor[i];
        }
    }
    return max;
}

int suma(vector<int> wektor)
{
    int wynik = 0;
    for (int i = 0; i < wektor.size(); i++)
    {
        wynik = wynik + wektor[i];
    }
    return wynik;
}

double srednia(vector<int> wektor)
{
    if (wektor.size() == 0)
    {
        return 0;
    }
    return (double)suma(wektor) / wektor.size();
}

// & - the function changes the order of the caller's elements
void sortowanieBabelkowe(vector<int> &wektor)
{
    int n = wektor.size();
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
}

int main()
{
    srand(time(0));

    vector<int> liczby;
    int ile;
    do
    {
        cout << "Enter number of elements (1-50): ";
        cin >> ile;
    } while (ile < 1 || ile > 50);

    wypelnijLosowo(liczby, ile, 1, 100);

    cout << "Generated vector: ";
    wypisz(liczby);
    cout << "Min Value: " << znajdzMin(liczby) << endl;
    cout << "Max Value: " << znajdzMax(liczby) << endl;
    cout << "Sum: " << suma(liczby) << endl;
    cout << "Average: " << srednia(liczby) << endl;

    sortowanieBabelkowe(liczby);
    cout << "Bubble sorted vector: ";
    wypisz(liczby);

    return 0;
}
