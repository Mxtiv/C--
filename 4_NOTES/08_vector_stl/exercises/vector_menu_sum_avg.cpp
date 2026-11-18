// ======================================================================
// char menu: print / add / sum / average of a vector
// Original file: unsorted/Vectors/paintbrushVectorDemo.cpp
// ======================================================================

#include <iostream>
#include <vector>
using namespace std;

void wypisz(vector<int> wektor)
{
    cout << "values: ";
    for (int i = 0; i < wektor.size(); i++)
    {
        cout << wektor[i];
        if (i != wektor.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
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
    return (double)suma(wektor) / wektor.size();
}

int main()
{
    vector<int> wektor;
    char wybor;
    do
    {
        cout << "\nselect an option\n";
        cout << "p - print elements\n";
        cout << "a - add new element\n";
        cout << "v - average of all elements\n";
        cout << "s - sum\n";
        cout << "q - quit\n";
        cout << "Selection: ";
        cin >> wybor;

        if (wybor == 'p' || wybor == 'P')
        {
            if (wektor.size() != 0)
            {
                wypisz(wektor);
            }
            else
            {
                cout << "no data" << endl;
            }
        }
        else if (wybor == 'a' || wybor == 'A')
        {
            int liczba;
            cout << "number: ";
            cin >> liczba;
            wektor.push_back(liczba);
        }
        else if (wybor == 's' || wybor == 'S')
        {
            if (wektor.size() != 0)
            {
                cout << "sum: " << suma(wektor) << endl;
            }
            else
            {
                cout << "no data" << endl;
            }
        }
        else if (wybor == 'v' || wybor == 'V')
        {
            if (wektor.size() != 0)
            {
                cout << "average: " << srednia(wektor) << endl;
            }
            else
            {
                cout << "no data" << endl;
            }
        }
        else if (wybor == 'q' || wybor == 'Q')
        {
            cout << "Goodbye!" << endl;
        }
    } while (wybor != 'q' && wybor != 'Q');

    return 0;
}
