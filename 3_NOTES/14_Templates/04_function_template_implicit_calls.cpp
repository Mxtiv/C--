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
    cout << "konkretyzacja";
    return zmienna1 + zmienna2;
}
template <> // definicja szablonu specjalizowanego
double funkcja<double, float>(
    double zmienna, float zmienna1)
{
    cout << "specjalizacja double float "<<endl;
    return zmienna;
}
template <>
float funkcja<float, double>(float zmienna, double zmienna7)
{
    cout << "specjalizacja float double"<<endl;
    return zmienna;
}
int main()
{
    double bot = 1.5;
    float sam = 2.5f;
    cout << endl;
    funkcja(bot,sam); // specjalizowanie szablonu funkcji niejawne double,float
    funkcja(2.0f,2.0);// specjalizowanie szablonu funkcji  niejawne float,double
    funkcja(2,2.0);//konkretyzacja niejawna int,double
    return 0;
}