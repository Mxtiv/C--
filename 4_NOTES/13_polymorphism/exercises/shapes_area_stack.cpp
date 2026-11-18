// ======================================================================
// Figura -> Trojkat/Rownoleglobok/Kolo, base pointer to stack objects
// Original file: Classes/Polimorfizm/X) Zadanie figury stos, virtual/main.cpp
// FIXED - the bug was: podstawa * wysokosc / 2 is integer division
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
        return podstawa * wysokosc / 2.0;
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
    // obiekty na STOSIE (zwykle zmienne) - nie trzeba new ani delete
    Trojkat trojkat(1, 2);
    Rownoleglobok rownoleglobok(2, 1);
    Kolo kolo(4);

    Figura *figura;

    figura = &trojkat;
    cout << "Pole trojkata: " << figura->pole() << endl;

    figura = &rownoleglobok;
    cout << "Pole rownolegloboku: " << figura->pole() << endl;

    figura = &kolo;
    cout << "Pole kola: " << figura->pole() << endl;
    return 0;
}
