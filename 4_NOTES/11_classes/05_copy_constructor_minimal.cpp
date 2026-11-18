// ======================================================================
// Minimal copy constructor (konstruktor kopiujący).
// Its parameter MUST be a reference: Klasa(const Klasa &wzor) - this one
// signature is the topic here (by value it would have to copy itself forever).
// Original file: Classes/konstruktory/kopiujacy.cpp
// ======================================================================

#include <iostream>
using namespace std;

class Prostokat
{
private:
    int bok1;
    int bok2;

public:
    Prostokat(int nowyBok1, int nowyBok2)
    {
        bok1 = nowyBok1;
        bok2 = nowyBok2;
    }

    // konstruktor kopiujący - nowy obiekt jako kopia innego
    Prostokat(const Prostokat &wzor)
    {
        bok1 = wzor.bok1;      // obiekt tej samej klasy - private jest dostępne
        bok2 = wzor.bok2;
        cout << "Wywolano konstruktor kopiujacy" << endl;
    }

    void wypisz()
    {
        cout << bok1 << " x " << bok2 << endl;
    }
};

int main()
{
    Prostokat p1(5, 10);
    Prostokat p2(p1);     // kopia - wywołanie jawne
    Prostokat p3 = p1;    // kopia - wywołanie niejawne

    p1.wypisz();
    p2.wypisz();
    p3.wypisz();

    return 0;
}
