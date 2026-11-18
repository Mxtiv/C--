// ======================================================================
// 3-level chain Pracownik -> Nauczyciel -> Wychowawca (textbook comments)
// Original file: unsorted/various/dziedziczenie1.cpp
// ======================================================================

#include <iostream>
#include <string>
using namespace std;

// poziom 1 - klasa bazowa
class Pracownik
{
protected:
    string imie;
    string nazwisko;

public:
    Pracownik(string noweImie, string noweNazwisko)
    {
        imie = noweImie;
        nazwisko = noweNazwisko;
    }

    string zwrocDane()
    {
        return imie + " " + nazwisko;
    }
};

// poziom 2 - dziedziczy po Pracownik
class Nauczyciel : public Pracownik
{
protected:
    string przedmiot;

public:
    Nauczyciel(string noweImie, string noweNazwisko, string nowyPrzedmiot) : Pracownik(noweImie, noweNazwisko)
    {
        przedmiot = nowyPrzedmiot;
    }

    string zwrocDane()
    {
        return imie + " " + nazwisko + ", przedmiot: " + przedmiot;
    }
};

// poziom 3 - dziedziczy po Nauczyciel (a wiec posrednio tez po Pracownik)
class Wychowawca : public Nauczyciel
{
private:
    string klasa;

public:
    Wychowawca(string noweImie, string noweNazwisko, string nowyPrzedmiot, string nowaKlasa) : Nauczyciel(noweImie, noweNazwisko, nowyPrzedmiot)
    {
        klasa = nowaKlasa;
    }

    // imie i nazwisko (z Pracownik) oraz przedmiot (z Nauczyciel) sa tu dostepne,
    // bo w obu klasach sa protected, a dziedziczenie jest publiczne
    string zwrocDane()
    {
        return imie + " " + nazwisko + ", klasa: " + klasa + ", przedmiot: " + przedmiot;
    }
};

int main()
{
    Wychowawca wychowawca("Jan", "Cieslar", "wychowanie fizyczne", "5A");
    cout << "Dane wychowawcy: " << wychowawca.zwrocDane() << endl;
    return 0;
}
