// ======================================================================
// public inheritance: derived object uses inherited public fields; method hiding
// Original file: Classes/Klasy z dziedziczeniem/Publiczne dziedziczenie, zmienianie publicznych dziedziczonych wartosci/main.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

// klasa bazowa
// (pola sa public tylko po to, zeby pokazac, ze main ma do nich dostep)
class Pracownik
{
public:
    string imie;
    string nazwisko;

    string zwrocDane()
    {
        return imie + " " + nazwisko;
    }
};

// klasa pochodna - dziedziczenie PUBLICZNE: public z bazy zostaje public
class Nauczyciel : public Pracownik
{
public:
    string przedmiot;

    // ta sama nazwa co w bazie -> metoda z bazy jest PRZESLONIETA (ukryta)
    string zwrocDane()
    {
        return imie + " " + nazwisko + ", przedmiot: " + przedmiot;
    }
};

int main()
{
    Nauczyciel nauczyciel;
    nauczyciel.imie = "Jan";            // mamy dostep do imienia i nazwiska,
    nauczyciel.nazwisko = "Kowalski";   // bo dziedziczenie jest publiczne
    nauczyciel.przedmiot = "elektronika";

    cout << "Dane nauczyciela: " << nauczyciel.zwrocDane() << endl;
    cout << "Wersja z klasy bazowej: " << nauczyciel.Pracownik::zwrocDane() << endl;
    return 0;
}
