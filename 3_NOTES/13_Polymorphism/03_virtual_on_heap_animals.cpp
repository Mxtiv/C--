// ======================================================================
// Zwierze* pointing at Lew/Pies/Kot created with new, virtual method, delete
// Original file: Classes/Polimorfizm/Polimorfizm na stercie, sterta/main.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Zwierze
{
public:
    // virtual = wersja metody wybierana w czasie dzialania programu,
    // wedlug typu OBIEKTU, a nie typu wskaznika
    virtual void wydajDzwiek()
    {
        cout << "(jakis dzwiek)" << endl;
    }

    // virtual destruktor - tylko dlatego, ze obiekty tworzymy przez new
    // i usuwamy przez delete wskaznika do klasy bazowej (wiecej w 05_)
    virtual ~Zwierze()
    {
    }
};

class Lew : public Zwierze
{
private:
    string ryk;

public:
    Lew(string nowyRyk)
    {
        ryk = nowyRyk;
    }

    void wydajDzwiek()
    {
        cout << ryk << endl;
    }
};

class Pies : public Zwierze
{
private:
    string szczekniecie;

public:
    Pies(string noweSzczekniecie)
    {
        szczekniecie = noweSzczekniecie;
    }

    void wydajDzwiek()
    {
        cout << szczekniecie << endl;
    }
};

class Kot : public Zwierze
{
private:
    string miauczenie;

public:
    Kot(string noweMiauczenie)
    {
        miauczenie = noweMiauczenie;
    }

    void wydajDzwiek()
    {
        cout << miauczenie << endl;
    }
};

int main()
{
    Zwierze *zwierze;               // wskaznik do klasy bazowej

    zwierze = new Lew("RYK");       // obiekt na stercie (heap)
    zwierze->wydajDzwiek();         // Lew::wydajDzwiek - dzieki virtual
    delete zwierze;

    zwierze = new Pies("HAU");
    zwierze->wydajDzwiek();
    delete zwierze;

    zwierze = new Kot("MIAU");
    zwierze->wydajDzwiek();
    delete zwierze;
    return 0;
}
