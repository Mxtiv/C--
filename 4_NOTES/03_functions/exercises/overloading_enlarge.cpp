// ======================================================================
// overloads powieksz(int), (int,int), (double)
// Original file: unsorted/various/functionOverload.cpp
// ======================================================================

#include <iostream>
using namespace std;

// Przeładowanie (overloading) nazwy funkcji - te same nazwy funkcji
// rozróżniamy po rodzaju lub liczbie parametrów.
int powieksz(int liczba1)
{
    return liczba1 + 1;
}

int powieksz(int liczba1, int liczba2)
{
    return liczba1 + liczba2;
}

double powieksz(double liczba1)
{
    int oIle;
    cout << "o ile powiekszyc: ";
    cin >> oIle;
    return liczba1 + oIle;
}

int main()
{
    int liczba1 = 4;
    double liczba2 = 5.5;

    cout << powieksz(liczba1) << endl;      // 5
    cout << powieksz(liczba1, 3) << endl;   // 7
    cout << powieksz(liczba2) << endl;      // 5.5 + what you type
    return 0;
}
