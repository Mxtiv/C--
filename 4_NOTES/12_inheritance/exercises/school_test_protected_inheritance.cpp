// ======================================================================
// test: protected inheritance
// Original file: unsorted/various/heritagepopek.cpp
// FIXED - the bug was: main called setP1()/setP2(), which are protected after protected inheritance; added public methods in the derived class
// ======================================================================

// Grupa A: klasa bazowa ma wlasnosc, ktora sie dziedziczy, ale nie jest dostepna w funkcji main
// przez operator wyluskania, oraz wlasnosc private.
// Klasa pochodna ma miec odziedziczone wlasnosci chronione oraz metode wyswietl.
// W funkcji main wyedytuj wszystkie wlasnosci.

#include <iostream>
using namespace std;

class Bazowa
{
private:
    int p1;

protected:
    int p2;

public:
    Bazowa()
    {
        p1 = 1;
        p2 = 3;
    }

    int getP1()
    {
        return p1;
    }

    void setP1(int wartosc)
    {
        p1 = wartosc;
    }
};

class Pochodna : protected Bazowa
{
public:
    Pochodna(int nowe1, int nowe2)
    {
        setP1(nowe1);           // p1 jest private w bazie -> tylko przez setter
        p2 = nowe2;             // p2 jest protected -> mozna po nazwie
    }

    void zmienP1(int wartosc)   // publiczna metoda, bo setP1 jest teraz protected
    {
        setP1(wartosc);
    }

    void zmienP2(int wartosc)
    {
        p2 = wartosc;
    }

    void wyswietl()
    {
        cout << "p1 = " << getP1() << ", p2 = " << p2 << endl;
    }
};

int main()
{
    Pochodna obiekt(1, 3);
    obiekt.zmienP1(4);
    obiekt.zmienP2(6);
    obiekt.wyswietl();
    return 0;
}
