// ======================================================================
// new double[rozmiar] with the size from the user, average, delete[]
// Original file: Arrays/dynamic.cpp
// ======================================================================

#include <iostream>
using namespace std;

int main()
{
    int rozmiar;
    do
    {
        cout << "Enter the number of elements: ";
        cin >> rozmiar;
    } while (rozmiar < 1);

    // Dynamically allocate an array - its size is known only now
    double *liczby = new double[rozmiar];

    cout << "Enter " << rozmiar << " numbers: " << endl;
    double suma = 0;
    for (int i = 0; i < rozmiar; i++)
    {
        cin >> liczby[i];
        suma = suma + liczby[i];
    }

    double srednia = suma / rozmiar;
    cout << "Average: " << srednia << endl;

    // Free allocated memory
    delete[] liczby;

    return 0;
}
