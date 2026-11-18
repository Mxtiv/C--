// ======================================================================
// specialize ONE method: template<> void Szablon<double,float>::wyswietl()
// Original file: unsorted/classtemplate/ex2.cpp
// ======================================================================

/* Napisz klase "Szablon" z dwoma polami i metoda wyswietl, ktora wyswietla komunikaty:
   dla specjalizacji double,float - "spec double float"
   dla specjalizacji int,float    - "spec int float"
   dla konkretyzacji              - "konkretyzacja" */

#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Szablon
{
public:
    T1 pole1;
    T2 pole2;

    void wyswietl()
    {
        cout << "konkretyzacja" << endl;
    }
};

// zapis skrocony: specjalizujemy TYLKO JEDNA metode (reszta klasy z szablonu ogolnego)
template <>
void Szablon<double, float>::wyswietl()
{
    cout << "spec double float" << endl;
}

// zapis pelny: specjalizacja calej klasy
template <>
class Szablon<int, float>
{
public:
    int pole1;
    float pole2;

    void wyswietl()
    {
        cout << "spec int float" << endl;
    }
};

int main()
{
    Szablon<double, float> szablon1;
    szablon1.wyswietl();
    Szablon<int, float> szablon2;
    szablon2.wyswietl();
    Szablon<int, int> szablon3;
    szablon3.wyswietl();
    return 0;
}
