// ======================================================================
// public / protected / private members through protected inheritance; Bazowa::metoda() call
// Original file: Classes/dzieciczenie/adam.cpp
// ======================================================================

#include <iostream>
using namespace std;

class Bazowa
{
public:
    int wlasnosc1;              // public - widac wszedzie

    void setWlasnosc3(int wartosc)
    {
        wlasnosc3 = wartosc;
    }

    int getWlasnosc3()
    {
        return wlasnosc3;
    }

protected:
    int wlasnosc2;              // protected - widac w klasach pochodnych

private:
    int wlasnosc3;              // private - widac TYLKO w klasie Bazowa
};

// dziedziczenie protected: wlasnosc1 i wlasnosc2 sa w Pochodnej protected,
// wlasnosc3 jest niedostepna - mozna jej uzywac tylko przez metody z bazy
class Pochodna : protected Bazowa
{
public:
    void setWlasnosc1(int wartosc)
    {
        wlasnosc1 = wartosc;
    }

    int getWlasnosc1()
    {
        return wlasnosc1;
    }

    void setWlasnosc2(int wartosc)
    {
        wlasnosc2 = wartosc;
    }

    int getWlasnosc2()
    {
        return wlasnosc2;
    }

    // wlasnosc3 = wartosc; -> BLAD (private w bazie), wiec wolamy metode z bazy
    void setWlasnosc3(int wartosc)
    {
        Bazowa::setWlasnosc3(wartosc);
    }

    int getWlasnosc3()
    {
        return Bazowa::getWlasnosc3();
    }
};

int main()
{
    Pochodna obiekt;

    obiekt.setWlasnosc1(11);
    obiekt.setWlasnosc2(22);
    obiekt.setWlasnosc3(33);

    cout << "wlasnosc1: " << obiekt.getWlasnosc1() << endl;
    cout << "wlasnosc2: " << obiekt.getWlasnosc2() << endl;
    cout << "wlasnosc3: " << obiekt.getWlasnosc3() << endl;
    return 0;
}
