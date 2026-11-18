// ======================================================================
// virtual destructor + override keyword (override is NOT needed at the exam;
// virtual destructor only when you delete through a base pointer)
// Original file: unsorted/various/virtual1.cpp
// ======================================================================

#include <iostream>
using namespace std;

class Pojazd
{
public:
    // virtual destruktor: dzieki niemu "delete wskaznikBazowy;" wywola tez
    // destruktor klasy pochodnej. Potrzebny TYLKO gdy obiekt pochodny tworzysz
    // przez new i usuwasz przez wskaznik do bazy. Gdy obiekty sa zwyklymi
    // zmiennymi (Samochod s(120); Pojazd *p = &s;) - niepotrzebny.
    virtual ~Pojazd()
    {
    }

    virtual void wyswietlTyp() = 0;
    virtual void wyswietlPredkosc() = 0;
};

class Samochod : public Pojazd
{
private:
    int predkosc;

public:
    Samochod(int nowaPredkosc)
    {
        predkosc = nowaPredkosc;
    }

    // override = kompilator sprawdza, czy w bazie jest taka metoda virtual
    // (chroni przed literowka). Opcjonalne - na egzaminie niepotrzebne.
    void wyswietlTyp() override
    {
        cout << "Typ: samochod" << endl;
    }

    void wyswietlPredkosc() override
    {
        cout << "Predkosc: " << predkosc << " km/h" << endl;
    }
};

class Rower : public Pojazd
{
private:
    int predkosc;

public:
    Rower(int nowaPredkosc)
    {
        predkosc = nowaPredkosc;
    }

    // bez override tez dziala tak samo
    void wyswietlTyp()
    {
        cout << "Typ: rower" << endl;
    }

    void wyswietlPredkosc()
    {
        cout << "Predkosc: " << predkosc << " km/h" << endl;
    }
};

int main()
{
    Pojazd *pojazd1 = new Samochod(120);
    Pojazd *pojazd2 = new Rower(25);

    pojazd1->wyswietlTyp();
    pojazd1->wyswietlPredkosc();
    pojazd2->wyswietlTyp();
    pojazd2->wyswietlPredkosc();

    delete pojazd1;     // OK - bo ~Pojazd() jest virtual
    delete pojazd2;
    return 0;
}
