// ======================================================================
// 3 type parameters, 2 full class specializations
// Original file: unsorted/typename template/dollops.cpp
// ======================================================================

#include <iostream>
using namespace std;

template <typename T1, typename T2, typename T3>
class SzablonKlasy
{
public:
    T1 pole1;
    T2 pole2;
    T3 pole3;

    void wyswietl()
    {
        cout << "konkretyzacja" << endl;
    }
};

// specjalizacja dla (double, float, int)
template <>
class SzablonKlasy<double, float, int>
{
public:
    double pole1;
    float pole2;
    int pole3;

    void wyswietl()
    {
        cout << "spec double float int" << endl;
    }
};

// specjalizacja dla (int, float, double)
template <>
class SzablonKlasy<int, float, double>
{
public:
    int pole1;
    float pole2;
    double pole3;

    void wyswietl()
    {
        cout << "spec int float double" << endl;
    }
};

int main()
{
    SzablonKlasy<int, float, double> obiekt1;
    obiekt1.wyswietl();    // spec int float double

    SzablonKlasy<double, float, int> obiekt2;
    obiekt2.wyswietl();    // spec double float int

    SzablonKlasy<int, int, int> obiekt3;
    obiekt3.wyswietl();    // konkretyzacja

    SzablonKlasy<char, double, float> obiekt4;
    obiekt4.wyswietl();    // konkretyzacja

    return 0;
}
