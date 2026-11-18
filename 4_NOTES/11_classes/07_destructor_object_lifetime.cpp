// ======================================================================
// When does the destructor (~Klasa) run?
//   - at the end of the block { } where the object was created
//   - at delete (object made with new)
//   - at the end of a function (local object)
// Original file: unsorted/calfmatthew/destructor.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Pracownik
{
private:
    string imie;

public:
    Pracownik(string noweImie)
    {
        imie = noweImie;
        cout << "konstruktor: " << imie << endl;
    }

    // destruktor - bez parametrów, bez typu, jeden na klasę
    ~Pracownik()
    {
        cout << "destruktor: " << imie << endl;
    }
};

void funkcjaPomocnicza()
{
    Pracownik lokalny("lokalny w funkcji");
    cout << "koniec funkcji" << endl;
}   // tu destruktor obiektu lokalnego

int main()
{
    {
        Pracownik p1("p1 w bloku");
        cout << "koniec bloku" << endl;
    }   // tu destruktor p1

    Pracownik *wskaznik = new Pracownik("na stercie");
    delete wskaznik;   // delete -> destruktor

    funkcjaPomocnicza();

    Pracownik p2("p2 w main");
    cout << "koniec main" << endl;
    return 0;
}   // tu destruktor p2
