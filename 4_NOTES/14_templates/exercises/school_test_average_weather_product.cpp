// ======================================================================
// test: specializations int,float / double,double + generic
// Original file: unsorted/typename template/sprawdzian.cpp
// FIXED - the bug was: int return type truncates the average (now returns double)
// ======================================================================

// Napisz szablon funkcji pobierajacej dwa argumenty, ktora bedzie sie dwa razy specjalizowac i raz konkretyzowac dla zmiennych typu:
// int,float     - zwraca srednia argumentow (z przecinkiem)
// float,int     - komunikat o pogodzie
// double,double - iloczyn argumentow
// Sprobuj tak skonstruowac szablon, by byly mozliwe wywolania niejawne. Wywolaj jawnie i niejawnie w sumie trzy razy funkcje.

#include <iostream>
using namespace std;

template <typename T1, typename T2>
double funkcja(T1 zmienna1, T2 zmienna2)        // typ zwracany double, zeby srednia miala przecinek
{
    cout << "Piekna pogoda dzisiaj. Temperatura w stopniach Celsjusza:" << endl;
    return 28;
}

template <>
double funkcja<int, float>(int zmienna1, float zmienna2)
{
    cout << "Int float - srednia" << endl;
    return (zmienna1 + zmienna2) / 2.0;
}

template <>
double funkcja<double, double>(double zmienna1, double zmienna2)
{
    cout << "Double double - iloczyn" << endl;
    return zmienna1 * zmienna2;
}

int main()
{
    cout << funkcja<int, float>(6, 3.0f) << endl;      // jawnie    -> specjalizacja
    cout << funkcja<float, int>(2.5f, 3) << endl;      // jawnie    -> konkretyzacja (pogoda)
    cout << funkcja(2.0, 3.0) << endl;                 // niejawnie -> specjalizacja double,double
    return 0;
}
