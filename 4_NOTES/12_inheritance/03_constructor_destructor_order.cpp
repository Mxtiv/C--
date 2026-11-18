// ======================================================================
// ctor order base -> derived, dtor order derived -> base, calling the base ctor: Nauczyciel(...) : Pracownik(a, b)
// Original file: Classes/dzieciczenie/destruktory.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

class Pracownik
{
protected:
    string imie;
    string nazwisko;

public:
    Pracownik()
    {
        imie = "";
        nazwisko = "";
        cout << "konstruktor domyslny BAZOWEJ" << endl;
    }

    Pracownik(string noweImie, string noweNazwisko)
    {
        imie = noweImie;
        nazwisko = noweNazwisko;
        cout << "konstruktor z parametrami BAZOWEJ" << endl;
    }

    ~Pracownik()
    {
        cout << "DESTRUKTOR klasy bazowej" << endl;
    }
};

class Nauczyciel : public Pracownik
{
private:
    string przedmiot;

public:
    // nie wybralismy konstruktora bazy -> automatycznie wywola sie Pracownik()
    Nauczyciel()
    {
        przedmiot = "";
        cout << "konstruktor domyslny POCHODNEJ" << endl;
    }

    // ": Pracownik(...)" = wybieramy, ktory konstruktor bazy ma sie wywolac
    // (tak przekazuje sie dane do konstruktora klasy bazowej)
    Nauczyciel(string noweImie, string noweNazwisko, string nowyPrzedmiot) : Pracownik(noweImie, noweNazwisko)
    {
        przedmiot = nowyPrzedmiot;
        cout << "konstruktor z parametrami POCHODNEJ" << endl;
    }

    ~Nauczyciel()
    {
        cout << "DESTRUKTOR klasy pochodnej" << endl;
    }

    string zwrocDane()
    {
        return imie + " " + nazwisko + ", przedmiot: " + przedmiot;
    }
};

int main()
{
    // kolejnosc konstruktorow: najpierw BAZA, potem POCHODNA
    cout << "--- nauczyciel1 ---" << endl;
    Nauczyciel nauczyciel1;

    cout << "--- nauczyciel2 ---" << endl;
    Nauczyciel nauczyciel2("Adam", "Nowak", "jezyk niemiecki");
    cout << "Dane nauczyciela: " << nauczyciel2.zwrocDane() << endl;

    // koniec main -> destruktory: najpierw POCHODNA, potem BAZA
    // (obiekty niszczone w odwrotnej kolejnosci: najpierw nauczyciel2, potem nauczyciel1)
    cout << "--- koniec main ---" << endl;
    return 0;
}
