// ======================================================================
// task: private/protected/public members + protected inheritance
// Original file: Classes/Klasy z dziedziczeniem/X) Zadanie dziedziczenie protected i dzialanie na wartosciach protected/main.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Pracownik
{
private:
    string imie;

protected:
    string id;

public:
    string nazwisko;

    Pracownik()
    {
        imie = "";
        id = "";
        nazwisko = "";
    }

    void setImie(string noweImie)
    {
        imie = noweImie;
    }

    string getImie()
    {
        return imie;
    }
};

// dziedziczenie PROTECTED: public z bazy (nazwisko, setImie, getImie) staje sie protected
class Nauczyciel : protected Pracownik
{
public:
    string przedmiot;

    void zmienImie(string noweImie)
    {
        setImie(noweImie);
    }

    void setNazwisko(string noweNazwisko)
    {
        nazwisko = noweNazwisko;
    }

    string getNazwisko()
    {
        return nazwisko;
    }

    string zwrocDane()
    {
        return getImie() + " " + nazwisko + ", przedmiot: " + przedmiot;
    }
};

int main()
{
    Nauczyciel nauczyciel;
    nauczyciel.zmienImie("Jan");
    nauczyciel.setNazwisko("Kowalski");
    nauczyciel.przedmiot = "elektronika";
    cout << "Dane nauczyciela: " << nauczyciel.zwrocDane() << endl;
    return 0;
}
