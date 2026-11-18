// ======================================================================
// pure virtual = 0, abstract class Zwierze, Pies/Kot through a base pointer
// Original file: Classes/spr/sprawdzianpolimorfia/main.cpp
// ======================================================================

#include <iostream>
using namespace std;

// klasa ABSTRAKCYJNA = ma co najmniej jedna metode czysto wirtualna (= 0)
// - nie da sie utworzyc jej obiektu
// - kazda klasa pochodna MUSI napisac te metode (inaczej tez jest abstrakcyjna)
class Zwierze
{
public:
    virtual void dajGlos() = 0;     // metoda czysto wirtualna - bez ciala
};

class Pies : public Zwierze
{
public:
    void dajGlos()
    {
        cout << "Hau! - pies" << endl;
    }
};

class Kot : public Zwierze
{
public:
    void dajGlos()
    {
        cout << "Miau! - kot" << endl;
    }
};

int main()
{
    // Zwierze zwierze;   // BLAD - nie mozna utworzyc obiektu klasy abstrakcyjnej
    Zwierze *wskaznik;    // ale wskaznik do niej - mozna

    Pies pies;
    Kot kot;

    wskaznik = &pies;
    wskaznik->dajGlos();  // Pies::dajGlos

    wskaznik = &kot;
    wskaznik->dajGlos();  // Kot::dajGlos
    return 0;
}
