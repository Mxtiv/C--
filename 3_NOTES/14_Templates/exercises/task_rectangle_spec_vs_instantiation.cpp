// ======================================================================
// task: specialization float,double + instantiation int,float
// Original file: unsorted/classtemplate/pop1.cpp
// ======================================================================

// Stworz szablon klasy Prostokat, ktory zawiera pola bok1, bok2 i metode obwod.
// Zastosuj 2 parametry uogolnione. Wykonaj specjalizacje dla float,double i konkretyzacje dla int,float.
// Tak stworz definicje, aby specjalizacje i konkretyzacje wykonac jawnie i niejawnie.

#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Prostokat
{
public:
    T1 bok1;
    T2 bok2;

    T2 obwod();
};

template <typename T1, typename T2>
T2 Prostokat<T1, T2>::obwod()
{
    return 2 * bok1 + 2 * bok2;
}

// specjalizacja dla float, double
template <>
class Prostokat<float, double>
{
public:
    float bok1;
    double bok2;

    double obwod()
    {
        cout << "(specjalizacja) ";
        return 2 * bok1 + 2 * bok2;
    }
};

// konkretyzacja JAWNA dla int, float
template class Prostokat<int, float>;

int main()
{
    Prostokat<float, double> prostokat1;       // specjalizacja
    prostokat1.bok1 = 1.1f;
    prostokat1.bok2 = 2.2;
    cout << "Obwod wynosi " << prostokat1.obwod() << endl;

    Prostokat<int, float> prostokat2;          // gotowa wersja z konkretyzacji jawnej
    prostokat2.bok1 = 1;
    prostokat2.bok2 = 2.1f;
    cout << "Obwod wynosi " << prostokat2.obwod() << endl;

    Prostokat<int, int> prostokat3;            // konkretyzacja NIEJAWNA - przy tworzeniu obiektu
    prostokat3.bok1 = 3;
    prostokat3.bok2 = 4;
    cout << "Obwod wynosi " << prostokat3.obwod() << endl;

    return 0;
}
