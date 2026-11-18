// ======================================================================
// template<T1,T2> class Prostokat, method defined outside, full class specialization vs instantiation (konkretyzacja)
// Original file: Classes/TypenameTemplate.cpp
// ======================================================================

#include <iostream>
using namespace std;

// Szablon klasy Prostokat - dwa typy uogolnione T1 i T2
template <typename T1, typename T2>
class Prostokat
{
public:
    T1 bok1;
    T2 bok2;

    T2 pole()                     // metoda zdefiniowana w klasie
    {
        return bok1 * bok2;
    }

    T2 obwod();                   // tylko deklaracja
};

// definicja metody poza klasa - znowu linia template i Prostokat<T1, T2>::
template <typename T1, typename T2>
T2 Prostokat<T1, T2>::obwod()
{
    return 2 * bok1 + 2 * bok2;
}

// SPECJALIZACJA calej klasy dla <double, int> - piszemy klase od nowa
template <>
class Prostokat<double, int>
{
public:
    double bok1;
    int bok2;

    int pole()
    {
        return (int)(bok1 * bok2);
    }

    int obwod()
    {
        cout << "(specjalizacja double,int) ";
        return (int)(2 * bok1 + 2 * bok2);
    }
};

int main()
{
    Prostokat<double, int> prostokat1;        // uzyta specjalizacja
    prostokat1.bok1 = 1.1;
    prostokat1.bok2 = 2;
    cout << "Pole wynosi " << prostokat1.pole() << endl;     // 2
    cout << "Obwod wynosi " << prostokat1.obwod() << endl;   // 6

    Prostokat<int, double> prostokat2;        // brak specjalizacji -> konkretyzacja
    prostokat2.bok1 = 1;
    prostokat2.bok2 = 2.1;
    cout << "Pole wynosi " << prostokat2.pole() << endl;     // 2.1
    cout << "Obwod wynosi " << prostokat2.obwod() << endl;   // 6.2

    return 0;
}
