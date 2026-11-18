// ======================================================================
// test group B: private inheritance, base ctor call, getters/setters in the derived class
// Original file: unsorted/various/heritageA.cpp
// ======================================================================

#include <iostream>
using namespace std;

// klasa bazowa dla grupy B
class BazowaB
{
private:
    int wlasnoscPrywatna;

public:
    int wlasnoscPubliczna;

    BazowaB()
    {
        wlasnoscPrywatna = 0;
        wlasnoscPubliczna = 0;
    }

    BazowaB(int publiczna, int prywatna)
    {
        wlasnoscPubliczna = publiczna;
        wlasnoscPrywatna = prywatna;
    }

    int getPrywatna()
    {
        return wlasnoscPrywatna;
    }

    void setPrywatna(int wartosc)
    {
        wlasnoscPrywatna = wartosc;
    }
};

// dziedziczenie PRIVATE: wszystko z bazy jest teraz private w PochodnaB
class PochodnaB : private BazowaB
{
public:
    PochodnaB()
    {
    }

    PochodnaB(int publiczna, int prywatna) : BazowaB(publiczna, prywatna)
    {
    }

    int getPubliczna()
    {
        return wlasnoscPubliczna;
    }

    void setPubliczna(int wartosc)
    {
        wlasnoscPubliczna = wartosc;
    }

    // wlasnoscPrywatna nie jest widoczna nawet tutaj -> przez getter/setter z bazy
    int pobierzPrywatna()
    {
        return getPrywatna();
    }

    void zmienPrywatna(int wartosc)
    {
        setPrywatna(wartosc);
    }
};

int main()
{
    PochodnaB obiekt(15, 25);
    // obiekt.wlasnoscPubliczna = 1;   // BLAD - po dziedziczeniu private
    cout << "Publiczna: " << obiekt.getPubliczna() << ", prywatna: " << obiekt.pobierzPrywatna() << endl;

    obiekt.setPubliczna(35);
    obiekt.zmienPrywatna(45);
    cout << "Po zmianie: " << obiekt.getPubliczna() << ", " << obiekt.pobierzPrywatna() << endl;

    PochodnaB obiekt2;
    cout << "Domyslna publiczna: " << obiekt2.getPubliczna() << endl;
    return 0;
}
