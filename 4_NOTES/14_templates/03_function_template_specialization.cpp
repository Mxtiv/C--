// ======================================================================
// function template + 2 full specializations template<>; specialization beats instantiation
// Original file: unsorted/typename template/bollocks.cpp
// ======================================================================

#include <iostream>
using namespace std;

// szablon ogolny - z niego kompilator robi KONKRETYZACJE (instantiation)
template <typename T1, typename T2>
T1 funkcja(T2 zmienna)
{
    cout << "konkretyzacja" << endl;
    return zmienna;
}

// SPECJALIZACJA (specialization) - sami piszemy osobna wersje dla danych typow
template <>
double funkcja<double, float>(float zmienna)
{
    cout << "specjalizacja double float" << endl;
    return zmienna;
}

template <>
float funkcja<float, double>(double zmienna)
{
    cout << "specjalizacja float double" << endl;
    return zmienna;
}

int main()
{
    funkcja<double, float>(2);   // specjalizacja ma pierwszenstwo przed konkretyzacja
    funkcja<float, double>(3);   // druga specjalizacja
    funkcja<int, int>(2);        // brak specjalizacji dla int,int -> konkretyzacja
    return 0;
}
