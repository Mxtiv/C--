// ======================================================================
// virtual + multiple inheritance, Bazowa::metoda() calls
// Original file: Classes/Polimorfizm/Polimorfiz, virtual/main.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Imie
{
protected:
    string imie;

public:
    Imie(string noweImie)
    {
        imie = noweImie;
    }

    virtual void zwrocDane()    // bez virtual: wskaznik Imie* wypisze samo imie
    {
        cout << "imie: " << imie << endl;
    }
};

class Nazwisko
{
protected:
    string nazwisko;

public:
    Nazwisko(string noweNazwisko)
    {
        nazwisko = noweNazwisko;
    }

    virtual void zwrocDane()
    {
        cout << "nazwisko: " << nazwisko << endl;
    }
};

// dziedziczenie wielokrotne: Pracownik ma czesci Imie i Nazwisko
class Pracownik : public Imie, public Nazwisko
{
public:
    Pracownik(string noweImie, string noweNazwisko) : Imie(noweImie), Nazwisko(noweNazwisko)
    {
    }

    // obie bazy maja zwrocDane() -> trzeba podac, z ktorej klasy: Imie:: / Nazwisko::
    void zwrocDane()
    {
        Imie::zwrocDane();
        Nazwisko::zwrocDane();
    }
};

int main()
{
    Pracownik pracownik("Jan", "Kowalski");

    Imie *wskaznik = &pracownik;
    wskaznik->zwrocDane();      // virtual -> Pracownik::zwrocDane (imie + nazwisko)

    cout << "---" << endl;
    pracownik.Imie::zwrocDane(); // jawnie wersja z klasy Imie
    return 0;
}
