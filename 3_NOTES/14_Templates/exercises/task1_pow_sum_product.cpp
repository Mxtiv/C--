// ======================================================================
// task: 3 specializations of a 2-parameter function template
// Original file: unsorted/typename template/zadanie1.cpp
// ======================================================================

// Napisz szablon funkcji pobierajacej dwa argumenty, ktora bedzie sie specjalizowac dla zmiennych typu:
// int,float     - zwraca pierwszy argument do potegi drugiego
// float,double  - sume argumentow
// double,double - iloczyn argumentow
// Sprobuj tak skonstruowac szablon, by byly mozliwe wywolania niejawne. Wywolaj jawnie i niejawnie.

#include <iostream>
#include <cmath>
using namespace std;

template <typename T1, typename T2>
T1 oblicz(T1 zmienna1, T2 zmienna2)
{
    cout << "Ogolny szablon (konkretyzacja)" << endl;
    return zmienna1;
}

template <>
int oblicz<int, float>(int zmienna1, float zmienna2)
{
    cout << "Specjalizacja int float - potega" << endl;
    return (int)pow(zmienna1, zmienna2);
}

template <>
float oblicz<float, double>(float zmienna1, double zmienna2)
{
    cout << "Specjalizacja float double - suma" << endl;
    return zmienna1 + zmienna2;
}

template <>
double oblicz<double, double>(double zmienna1, double zmienna2)
{
    cout << "Specjalizacja double double - iloczyn" << endl;
    return zmienna1 * zmienna2;
}

int main()
{
    cout << oblicz<int, float>(2, 3.0f) << endl;        // jawnie
    cout << oblicz(2.5f, 3.5) << endl;                  // niejawnie: float, double
    cout << oblicz(2.0, 3.0) << endl;                   // niejawnie: double, double
    cout << oblicz(7, 'a') << endl;                     // int, char -> konkretyzacja
    return 0;
}
