// ======================================================================
// test: delegating ctors + protected inheritance
// Original file: Classes/spr/sprawdziandziedziczenie/main.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Baza
{
protected:
    int liczba;

public:
    string tekst;

    // konstruktor DELEGUJACY: Baza() przekazuje prace do Baza(int, string).
    // Na egzaminie wystarczy zwykle przypisanie w ciele: liczba = 1; tekst = "tekst";
    Baza() : Baza(1, "tekst")
    {
    }

    Baza(int nowaLiczba, string nowyTekst)
    {
        liczba = nowaLiczba;
        tekst = nowyTekst;
    }

    void wyswietl()
    {
        cout << "Liczba: " << liczba << endl;
        cout << "Tekst: " << tekst << endl;
    }
};

// dziedziczenie PROTECTED: liczba i tekst sa tu protected -> potrzebne settery/gettery
class Podrzedna : protected Baza
{
private:
    int podrzednaLiczba;

public:
    Podrzedna()
    {
        podrzednaLiczba = 4;
    }

    void setLiczba(int nowaLiczba)
    {
        liczba = nowaLiczba;
    }

    void setTekst(string nowyTekst)
    {
        tekst = nowyTekst;
    }

    void setPodrzednaLiczba(int nowaLiczba)
    {
        podrzednaLiczba = nowaLiczba;
    }

    void wyswietl()
    {
        Baza::wyswietl();       // metoda z klasy bazowej
        cout << "Podrzedna liczba: " << podrzednaLiczba << endl;
    }
};

int main()
{
    Baza baza;
    Podrzedna podrzedna;

    podrzedna.setTekst("pociag");
    podrzedna.setLiczba(2);
    podrzedna.setPodrzednaLiczba(3);
    podrzedna.wyswietl();

    cout << "=========================" << endl;
    baza.wyswietl();
    return 0;
}
