// ======================================================================
// implicit calls funkcja(a, b) choose the specialization from the argument types
// Original file: unsorted/typename template/niejawne.cpp
// FIXED - the bug was: bot/sam are uninitialized
// ======================================================================

#include <iostream>
using namespace std;

template <typename T1, typename T2>
T1 funkcja(T1 zmienna1, T2 zmienna2)
{
    cout << "konkretyzacja" << endl;
    return zmienna1 + zmienna2;
}

template <>
double funkcja<double, float>(double zmienna1, float zmienna2)
{
    cout << "specjalizacja double float" << endl;
    return zmienna1;
}

template <>
float funkcja<float, double>(float zmienna1, double zmienna2)
{
    cout << "specjalizacja float double" << endl;
    return zmienna1;
}

int main()
{
    double liczbaDouble = 1.5;
    float liczbaFloat = 2.5f;

    // wywolania NIEJAWNE - bez < >, typy wynikaja z argumentow
    funkcja(liczbaDouble, liczbaFloat);   // double,float -> specjalizacja
    funkcja(2.0f, 2.0);                   // float,double -> specjalizacja
    funkcja(2, 2.0);                      // int,double   -> konkretyzacja niejawna
    return 0;
}
