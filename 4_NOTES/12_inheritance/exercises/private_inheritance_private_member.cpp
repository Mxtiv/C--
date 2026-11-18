// ======================================================================
// same task with PRIVATE inheritance
// Original file: unsorted/various/zadaniejakiesdziedziczenie.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Pracownik
{
private:
    string imie;                // private - nawet klasa pochodna nie widzi go po nazwie

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

// dziedziczenie PRIVATE: nazwisko, setImie, getImie sa w Nauczycielu private
class Nauczyciel : private Pracownik
{
public:
    string przedmiot;

    // imie = noweImie; -> BLAD (private w bazie), wiec przez setter z bazy
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
    // nauczyciel.nazwisko = "Kowalski";  // BLAD - po dziedziczeniu private
    nauczyciel.zmienImie("Jan");
    nauczyciel.setNazwisko("Kowalski");
    nauczyciel.przedmiot = "elektronika";
    cout << "Dane nauczyciela: " << nauczyciel.zwrocDane() << endl;
    return 0;
}
