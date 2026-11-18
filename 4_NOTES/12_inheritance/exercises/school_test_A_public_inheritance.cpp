// ======================================================================
// test group A: public inheritance, protected field via derived getter/setter
// Original file: unsorted/various/heritageB.cpp
// ======================================================================

#include <iostream>
using namespace std;

// klasa bazowa dla grupy A
class BazowaA
{
protected:
    int wlasnoscChroniona;      // dziedziczy sie, ale w main jej nie widac

public:
    int wlasnoscPubliczna;

    BazowaA()
    {
        wlasnoscPubliczna = 0;
        wlasnoscChroniona = 0;
    }

    BazowaA(int publiczna, int chroniona)
    {
        wlasnoscPubliczna = publiczna;
        wlasnoscChroniona = chroniona;
    }
};

// klasa pochodna - dziedziczenie publiczne
class PochodnaA : public BazowaA
{
public:
    PochodnaA()
    {
    }

    PochodnaA(int publiczna, int chroniona) : BazowaA(publiczna, chroniona)
    {
    }

    int getChroniona()
    {
        return wlasnoscChroniona;
    }

    void setChroniona(int wartosc)
    {
        wlasnoscChroniona = wartosc;
    }
};

int main()
{
    PochodnaA obiekt(10, 20);
    cout << "Publiczna: " << obiekt.wlasnoscPubliczna << endl;
    cout << "Chroniona (przez getter): " << obiekt.getChroniona() << endl;

    obiekt.wlasnoscPubliczna = 15;
    obiekt.setChroniona(30);
    cout << "Po zmianie: " << obiekt.wlasnoscPubliczna << ", " << obiekt.getChroniona() << endl;

    PochodnaA obiekt2;
    cout << "Domyslna publiczna: " << obiekt2.wlasnoscPubliczna << endl;
    return 0;
}
