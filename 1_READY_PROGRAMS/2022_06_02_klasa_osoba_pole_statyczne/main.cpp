// ======================================================================
// INF.04-02-22.06-SG - klasa Osoba (forum): 2 pola private, publiczne pole statyczne
// liczba instancji, 3 konstruktory (bezparametrowy, 2 parametry, kopiujący), metoda
// "Cześć <argument>, mam na imię <imie>". Testy w programie głównym (część III).
// Spec + key checklist: README.md in this folder.
// ======================================================================
#include <iostream>
#include <string>
using namespace std;

/******************************************************
nazwa klasy:  Osoba
pola:         id - numer identyfikacyjny osoby
              imie - imię osoby
              liczbaOsob - (statyczne) liczba utworzonych obiektów klasy
metody:       przedstawSie, brak - wypisuje powitanie z imieniem lub "Brak danych"
informacje:   reprezentuje użytkownika forum
autor:        00000000000
*****************************************************/
class Osoba
{
private:                       // private = klasy potomne też nie mają dostępu
    int id;
    string imie;

public:
    static int liczbaOsob;

    Osoba()
    {
        id = 0;
        imie = "";
        liczbaOsob++;
    }

    Osoba(int id, string imie)
    {
        this->id = id;
        this->imie = imie;
        liczbaOsob++;
    }

    Osoba(const Osoba &inna)
    {
        id = inna.id;
        imie = inna.imie;
        liczbaOsob++;
    }

    void przedstawSie(string argument)
    {
        if (imie == "")
        {
            cout << "Brak danych" << endl;
        }
        else
        {
            cout << "Czesc " << argument << ", mam na imie " << imie << endl;
        }
    }
};

int Osoba::liczbaOsob = 0;

int main()
{
    cout << "Liczba zarejestrowanych osob to " << Osoba::liczbaOsob << endl;

    Osoba pierwsza;

    int id;
    string imie;
    cout << "Podaj id: ";
    cin >> id;
    cout << "Podaj imie: ";
    cin >> imie;
    Osoba druga(id, imie);

    Osoba trzecia(druga);            // konstruktor kopiujący, źródło ma wypełnione pola

    pierwsza.przedstawSie("Jan");
    druga.przedstawSie("Jan");
    trzecia.przedstawSie("Jan");

    cout << "Liczba zarejestrowanych osob to " << Osoba::liczbaOsob << endl;
    return 0;
}
