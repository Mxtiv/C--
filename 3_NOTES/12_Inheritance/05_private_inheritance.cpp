// ======================================================================
// private inheritance (task text included); access through derived-class methods
// Original file: unsorted/sprawdzian/heritagepop.cpp
// ======================================================================

// Zadanie: W klasie bazowej jedna wlasnosc ma byc dostepna w programie bezposrednio, a druga nie,
// ale ma byc dostepna w klasie pochodnej poprzez nazwe.
// W klasie pochodnej odziedziczone wlasnosci maja byc private. Wyedytuj wszystkie wlasnosci
// klasy pochodnej w programie glownym.

#include <iostream>
using namespace std;

class Bazowa
{
protected:
    int p1;                     // niedostepna w main, dostepna w pochodnej

public:
    int p2;                     // dostepna w main (dla obiektu klasy Bazowa)

    Bazowa()
    {
        p1 = 1;
        p2 = 3;
    }

    void setP1(int wartosc)
    {
        p1 = wartosc;
    }

    void setP2(int wartosc)
    {
        p2 = wartosc;
    }
};

// dziedziczenie PRIVATE: wszystko z bazy jest w Pochodnej private,
// wiec main moze zmieniac wartosci tylko przez publiczne metody Pochodnej
class Pochodna : private Bazowa
{
public:
    Pochodna(int nowe1, int nowe2)
    {
        p1 = nowe1;
        p2 = nowe2;
    }

    void zmienP1(int wartosc)
    {
        setP1(wartosc);
    }

    void zmienP2(int wartosc)
    {
        setP2(wartosc);
    }

    void wyswietl()
    {
        cout << "p1 = " << p1 << ", p2 = " << p2 << endl;
    }
};

int main()
{
    Pochodna obiekt(1, 3);
    // obiekt.p2 = 5;       // BLAD - po dziedziczeniu private p2 jest private
    // obiekt.setP2(5);     // BLAD - setP2 tez jest teraz private
    obiekt.zmienP1(4);
    obiekt.zmienP2(6);
    obiekt.wyswietl();
    return 0;
}
