// ======================================================================
// protected inheritance -> inherited public members become protected, so you need setters/getters (textbook comments)
// Original file: unsorted/various/dziedziczenieProtected.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

// klasa bazowa Pracownik
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

// klasa pochodna - dziedziczenie PROTECTED:
// public z bazy staje sie protected -> w klasie Nauczyciel jest dostep,
// ale w main juz NIE (nauczyciel.imie = "Jan"; -> blad)
class Nauczyciel : protected Pracownik
{
private:
    string przedmiot;

public:
    // settery i gettery MUSZA byc, bo odziedziczone pola sa protected
    void setImie(string noweImie)
    {
        imie = noweImie;
    }

    void setNazwisko(string noweNazwisko)
    {
        nazwisko = noweNazwisko;
    }

    void setPrzedmiot(string nowyPrzedmiot)
    {
        przedmiot = nowyPrzedmiot;
    }

    string getImie()
    {
        return imie;
    }

    string getNazwisko()
    {
        return nazwisko;
    }

    string getPrzedmiot()
    {
        return przedmiot;
    }

    string zwrocDane()
    {
        return imie + " " + nazwisko + ", przedmiot: " + przedmiot;
    }
};

int main()
{
    Nauczyciel nauczyciel;

    // nauczyciel.imie = "Jan";   // BLAD - imie jest teraz protected
    nauczyciel.setImie("Jan");
    nauczyciel.setNazwisko("Kowalski");
    nauczyciel.setPrzedmiot("elektronika");

    cout << "Dane nauczyciela: " << nauczyciel.zwrocDane() << endl;
    cout << "Samo imie (getter): " << nauczyciel.getImie() << endl;
    return 0;
}
