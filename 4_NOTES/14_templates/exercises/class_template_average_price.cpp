// ======================================================================
// class template with a constructor + full class specialization (average price)
// Original file: unsorted/classtemplate/mxtiv.cpp
// (simplified: the original also showed C++17 "Komorka k(10, 5.5f)" without < > -
//  not needed at the exam, always write the types: Komorka<int, float>)
// ======================================================================

#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Komorka
{
public:
    T1 cenaMax;
    T2 cenaMin;

    Komorka(T1 nowaCenaMax, T2 nowaCenaMin)
    {
        cenaMax = nowaCenaMax;
        cenaMin = nowaCenaMin;
    }

    double sredniaCena()
    {
        return (cenaMax + cenaMin) / 2.0;
    }
};

// specjalizacja dla <double, float>
template <>
class Komorka<double, float>
{
public:
    double cenaMax;
    float cenaMin;

    Komorka(double nowaCenaMax, float nowaCenaMin)
    {
        cenaMax = nowaCenaMax;
        cenaMin = nowaCenaMin;
    }

    double sredniaCena()
    {
        cout << "(specjalizacja double,float) ";
        return (cenaMax + cenaMin) / 2.0;
    }
};

int main()
{
    Komorka<int, float> komorka1(10, 5.5f);                 // konkretyzacja
    cout << "Srednia cena (int, float): " << komorka1.sredniaCena() << endl;

    Komorka<double, float> komorka2(15.5, 10.0f);           // specjalizacja
    cout << "Srednia cena (double, float): " << komorka2.sredniaCena() << endl;

    return 0;
}
