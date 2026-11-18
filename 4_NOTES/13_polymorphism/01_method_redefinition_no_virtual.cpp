// ======================================================================
// derived class redefines methods (no virtual, called directly on objects)
// Original file: Classes/Polimorfizm/Polimorfizm najprostszy publiczny/main.cpp
// ======================================================================

#include <iostream>
using namespace std;

class Bazowa
{
protected:
    int wartosc;

public:
    Bazowa()
    {
        wartosc = 1;
    }

    void wyswietl()
    {
        cout << "Bazowa, wartosc = " << wartosc << endl;
    }

    void powieksz()
    {
        wartosc++;
    }
};

class Pochodna : public Bazowa
{
public:
    // REDEFINICJA (przesloniecie) - ta sama nazwa i parametry co w bazie.
    // Bez virtual: ktora wersja sie wywola, zalezy od TYPU OBIEKTU w kodzie.
    void wyswietl()
    {
        cout << "Pochodna, wartosc = " << wartosc << endl;
    }

    void powieksz()
    {
        wartosc = wartosc + 2;
    }
};

int main()
{
    Bazowa bazowa;
    Pochodna pochodna;

    bazowa.powieksz();          // Bazowa::powieksz  -> 2
    pochodna.powieksz();        // Pochodna::powieksz -> 3

    bazowa.wyswietl();
    pochodna.wyswietl();
    pochodna.Bazowa::wyswietl();    // wersja z bazy mozna wywolac jawnie
    return 0;
}
