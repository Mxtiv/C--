// ======================================================================
// singleton that stores a value; the second getInstance returns the first object
// Original file: Singleton/singletonAI.cpp
// ======================================================================

#include <iostream>
#include <string>
#include <cstdlib>      // NULL
using namespace std;

/********************************************************
 * nazwa klasy: Ustawienia
 * opis klasy: singleton - jedyny obiekt z nazwa programu
 * pola: instancja - wskaznik na jedyny obiekt
 *       nazwa - zapamietana wartosc
 * autor: <numer zdającego>
 ********************************************************/
class Ustawienia
{
private:
    static Ustawienia *instancja;
    string nazwa;

    Ustawienia(string nowaNazwa)       // prywatny konstruktor
    {
        nazwa = nowaNazwa;
    }

public:
    static Ustawienia *getInstance(string nowaNazwa)
    {
        if (instancja == NULL)
        {
            instancja = new Ustawienia(nowaNazwa);   // wartosc liczy sie tylko przy PIERWSZYM wywolaniu
        }
        return instancja;
    }

    string getNazwa()
    {
        return nazwa;
    }
};

Ustawienia *Ustawienia::instancja = NULL;

int main()
{
    Ustawienia *u1 = Ustawienia::getInstance("Pierwszy");
    cout << u1->getNazwa() << endl;          // Pierwszy

    Ustawienia *u2 = Ustawienia::getInstance("Drugi");
    cout << u2->getNazwa() << endl;          // nadal Pierwszy - to ten sam obiekt

    if (u1 == u2)
    {
        cout << "Ten sam obiekt!" << endl;
    }
    else
    {
        cout << "Rozne obiekty!" << endl;
    }
    return 0;
}
