// ======================================================================
// WHEN is the copy constructor called? 4 cases:
//   Prostokat p2 = p1;   Prostokat p3(p1);   passing by value;   returning by value
// Also: methods defined OUTSIDE the class (Prostokat::pole).
// Original file: unsorted/various/konstruktorKopiujacy.cpp
// ======================================================================

#include <iostream>
using namespace std;

class Prostokat
{
private:
    double bok1;
    double bok2;

public:
    Prostokat();                              // prototypy - definicje niżej
    Prostokat(double nowyBok1, double nowyBok2);
    Prostokat(const Prostokat &wzor);         // kopiujący - parametr MUSI być referencją
    double pole();
};

Prostokat::Prostokat()
{
    cout << "konstruktor domyslny" << endl;
    bok1 = 0;
    bok2 = 0;
}

Prostokat::Prostokat(double nowyBok1, double nowyBok2)
{
    cout << "konstruktor z parametrami" << endl;
    bok1 = nowyBok1;
    bok2 = nowyBok2;
}

Prostokat::Prostokat(const Prostokat &wzor)
{
    cout << "konstruktor KOPIUJACY" << endl;
    bok1 = wzor.bok1;
    bok2 = wzor.bok2;
}

double Prostokat::pole()
{
    return bok1 * bok2;
}

// parametr przez wartość -> kopia przy wejściu
double policzPole(Prostokat prostokat)
{
    return prostokat.pole();
}

// zwracanie przez wartość -> (może być) kopia przy wyjściu
Prostokat zrobKwadrat(double bok)
{
    Prostokat kwadrat(bok, bok);
    return kwadrat;     // kompilator często pomija tę kopię (tzw. copy elision)
}

int main()
{
    cout << "--- p1" << endl;
    Prostokat p1(1, 2);

    cout << "--- p2 = p1" << endl;
    Prostokat p2 = p1;         // niejawne wywołanie kopiującego

    cout << "--- p3(p1)" << endl;
    Prostokat p3(p1);          // jawne wywołanie kopiującego

    cout << "--- przekazanie przez wartosc" << endl;
    double wynik = policzPole(p1);
    cout << "pole = " << wynik << endl;

    cout << "--- zwracanie przez wartosc" << endl;
    Prostokat p4 = zrobKwadrat(3);
    cout << "pole p4 = " << p4.pole() << endl;

    cout << "pole p2 = " << p2.pole() << ", pole p3 = " << p3.pole() << endl;
    return 0;
}
