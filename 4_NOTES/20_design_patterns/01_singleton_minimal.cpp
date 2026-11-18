// ======================================================================
// minimal singleton: private ctor, static instance pointer, getInstance()
// Original file: Singleton/singletonTailored.cpp
//
// Singleton = klasa, ktora moze miec TYLKO JEDEN obiekt.
//   1. konstruktor prywatny     -> nie da sie napisac  Singleton s;
//   2. static wskaznik instancja -> pamieta ten jeden obiekt
//   3. static getInstance()      -> tworzy obiekt przy pierwszym wywolaniu,
//                                   potem zwraca wciaz ten sam
// ======================================================================

#include <iostream>
#include <cstdlib>      // NULL
using namespace std;

class Singleton
{
private:
    static Singleton *instancja;

    Singleton()                       // prywatny konstruktor
    {
        cout << "Tworze jedyny obiekt" << endl;
    }

public:
    static Singleton *getInstance()
    {
        if (instancja == NULL)        // pierwszy raz - utworz obiekt
        {
            instancja = new Singleton();
        }
        return instancja;             // kazdy nastepny raz - ten sam obiekt
    }

    void przywitaj()
    {
        cout << "Jestem Singletonem" << endl;
    }
};

Singleton *Singleton::instancja = NULL;   // definicja pola static poza klasa

int main()
{
    // Singleton s;                   // BLAD - konstruktor jest prywatny

    Singleton *s1 = Singleton::getInstance();
    s1->przywitaj();
    Singleton *s2 = Singleton::getInstance();   // "Tworze..." NIE wypisze sie drugi raz
    s2->przywitaj();

    if (s1 == s2)
    {
        cout << "s1 i s2 to ten sam obiekt" << endl;
    }
    return 0;
}
