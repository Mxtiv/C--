// ======================================================================
// class Ulamek: 2 constructors, private method (skracanie przez NWD),
// friend functions dodaj / pomnoz, methods defined outside the class.
// (was misfiled under PESEL)
// Original file: Arrays/pesel/pesel_pyndzel.cpp
// ======================================================================

#include <iostream>
using namespace std;

class Ulamek
{
private:
    int licznik;
    int mianownik;
    void skroc();                        // metoda prywatna - tylko do użytku w klasie

public:
    Ulamek();
    Ulamek(int nowyLicznik, int nowyMianownik);
    void wypisz();

    // funkcje zaprzyjaźnione - zwykłe funkcje z dostępem do private
    friend Ulamek dodaj(Ulamek a, Ulamek b);
    friend Ulamek pomnoz(Ulamek a, Ulamek b);
};

Ulamek::Ulamek()
{
    licznik = 1;
    mianownik = 1;
}

Ulamek::Ulamek(int nowyLicznik, int nowyMianownik)
{
    licznik = nowyLicznik;
    if (nowyMianownik != 0)
    {
        mianownik = nowyMianownik;
    }
    else
    {
        cout << "Mianownik nie moze byc 0 - ustawiam 1" << endl;
        mianownik = 1;
    }
}

// skracanie: NWD metodą odejmowania
void Ulamek::skroc()
{
    if (licznik == 0)
    {
        mianownik = 1;
        return;
    }
    int a = licznik;
    int b = mianownik;
    if (a < 0)
    {
        a = -a;
    }
    if (b < 0)
    {
        b = -b;
    }
    while (a != b)
    {
        if (a > b)
        {
            a = a - b;
        }
        else
        {
            b = b - a;
        }
    }
    licznik = licznik / a;
    mianownik = mianownik / a;
}

void Ulamek::wypisz()
{
    skroc();
    cout << licznik << "/" << mianownik;
}

Ulamek dodaj(Ulamek a, Ulamek b)
{
    Ulamek wynik;
    wynik.licznik = a.licznik * b.mianownik + b.licznik * a.mianownik;
    wynik.mianownik = a.mianownik * b.mianownik;
    return wynik;
}

Ulamek pomnoz(Ulamek a, Ulamek b)
{
    Ulamek wynik;
    wynik.licznik = a.licznik * b.licznik;
    wynik.mianownik = a.mianownik * b.mianownik;
    return wynik;
}

int main()
{
    int l1;
    int m1;
    int l2;
    int m2;
    cout << "Podaj licznik i mianownik pierwszego ulamka: ";
    cin >> l1 >> m1;
    cout << "Podaj licznik i mianownik drugiego ulamka: ";
    cin >> l2 >> m2;

    Ulamek u1(l1, m1);
    Ulamek u2(l2, m2);

    u1.wypisz();
    cout << " + ";
    u2.wypisz();
    cout << " = ";
    dodaj(u1, u2).wypisz();
    cout << endl;

    u1.wypisz();
    cout << " * ";
    u2.wypisz();
    cout << " = ";
    pomnoz(u1, u2).wypisz();
    cout << endl;

    return 0;
}
