// ======================================================================
// same shapes created with new/delete
// Original file: Classes/Polimorfizm/X) Zadanie figury sterta, virtual/main.cpp
// FIXED - the bug was: integer division in triangle area
// ======================================================================

#include <iostream>
using namespace std;

class Figura
{
public:
    virtual double pole()
    {
        cout << "wywolales metode z klasy bazowej" << endl;
        return 0;
    }

    // potrzebny, bo usuwamy obiekty przez Figura* (wiecej w ../05_)
    virtual ~Figura()
    {
    }
};

class Trojkat : public Figura
{
private:
    int podstawa;
    int wysokosc;

public:
    Trojkat(int nowaPodstawa, int nowaWysokosc)
    {
        podstawa = nowaPodstawa;
        wysokosc = nowaWysokosc;
    }

    double pole()
    {
        return podstawa * wysokosc / 2.0;   // 2.0, nie 2 - inaczej dzielenie calkowite
    }
};

class Rownoleglobok : public Figura
{
private:
    int podstawa;
    int wysokosc;

public:
    Rownoleglobok(int nowaPodstawa, int nowaWysokosc)
    {
        podstawa = nowaPodstawa;
        wysokosc = nowaWysokosc;
    }

    double pole()
    {
        return podstawa * wysokosc;
    }
};

class Kolo : public Figura
{
private:
    int promien;

public:
    Kolo(int nowyPromien)
    {
        promien = nowyPromien;
    }

    double pole()
    {
        return 3.14 * promien * promien;
    }
};

int main()
{
    Figura *figura;

    figura = new Trojkat(2, 1);     // obiekt na stercie
    cout << "Pole trojkata: " << figura->pole() << endl;
    delete figura;

    figura = new Rownoleglobok(1, 1);
    cout << "Pole rownolegloboku: " << figura->pole() << endl;
    delete figura;

    figura = new Kolo(1);
    cout << "Pole kola: " << figura->pole() << endl;
    delete figura;
    return 0;
}
